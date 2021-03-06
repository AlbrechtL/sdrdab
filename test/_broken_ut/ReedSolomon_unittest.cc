//#ifdef GOOGLE_UNIT_TEST

#include "data_decoder.h"
#include "gtest/gtest.h"
#include "MatlabIO.h"
#include "myTimer.h"
#include <unistd.h>

using namespace std;

class ReedSolomonTest  : public ::testing::Test {
	protected:
		ReedSolomonTest() {
            param.guard_size = 504;
            param.fft_size = 2048;
            param.symbol_size = 2552;
            param.number_of_symbols = 76;
            param.null_size = 2656;
            param.frame_size = 196608;
            param.number_of_carriers = 1536;
            param.number_of_symbols_per_fic = 3;
            param.number_of_fib = 12;
            param.number_of_cif = 4;
            param.number_of_deqpsk_unit_for_read = 5;
            param.number_of_fib_per_cif = 3;
            param.number_samp_after_timedep = 3096;
            param.number_samp_after_vit = 768;
            param.sync_read_size = 199264;
            param.fic_size = 9216;
            param.number_cu_per_symbol = 48;
            param.number_symbols_per_cif = 18;
            param.dab_mode = DAB_MODE_I;

            inputLength = 1680;
            frameLength = 120;
            outputLength = (inputLength/frameLength)*(frameLength-NPAR);
            // outputLength = 1540;
            outLength = 1*outputLength;
            
            inTruth = new uint8_t[inputLength];
            outTruth = new uint8_t[outputLength];

            inputLoaded = false;
            outputLoaded = false;

            datadecoder = new DataDecoder(&param);
		}

		virtual ~ReedSolomonTest() {
            delete datadecoder;
			delete [] inTruth;
			delete [] outTruth;
		}

		virtual void SetUp() {
	        inputLoaded = MatlabIO::ReadData(inTruth, "./data/ut/daneRSWe.txt", inputLength);
            outputLoaded = MatlabIO::ReadData(outTruth, "./data/ut/daneRSWy.txt", outputLength);
		}
        DataDecoder * datadecoder;

        bool inputLoaded;
        bool outputLoaded;

        int inputLength;
        int frameLength;
        int outLength;
        size_t outputLength;

        uint8_t* inTruth;
        uint8_t* outTruth;

        ModeParameters param;        
};

TEST_F(ReedSolomonTest, speedTest) {
    ASSERT_TRUE(inputLoaded) << "TESTING CODE FAILED... could not load expected data";
    ASSERT_TRUE(outputLoaded) << "TESTING CODE FAILED... could not load expected data";

	uint8_t output[outLength];
	uint8_t tmpIn[inputLength];
    ReedSolomon rs;
	MyTimer mt;

	rs.initPolys();

	// 1000 trials
	for(size_t k = 0; k < 10000; k++) {
		memcpy(tmpIn, inTruth, inputLength*sizeof(uint8_t));
		mt.tic();
		rs.getErrorsAndDecode(tmpIn, inputLength);
		mt.tac2Buff();
	}

	for(size_t i = 0; i < outputLength; i++) {
		EXPECT_EQ(tmpIn[i], outTruth[i]) << "Reed-Solomon correction differ on position: " << i;
	}

    cout << "Test of one round (median): " << mt.medianMsfromBuff() << " [ms]" << endl;
}

TEST_F(ReedSolomonTest, singleRandomError) {
    ASSERT_TRUE(inputLoaded) << "TESTING CODE FAILED... could not load expected data";
    ASSERT_TRUE(outputLoaded) << "TESTING CODE FAILED... could not load expected data";

	uint8_t tmpIn[inputLength];
    ReedSolomon rs;
	MyTimer mt;

	rs.initPolys();
	srand(time(NULL));


	// 1000 trials
	for(size_t t=0; t<1000; ++t){
		memcpy(tmpIn, inTruth, inputLength*sizeof(uint8_t));

		size_t bytesPosition = rand()%inputLength;
		size_t bitPosition = rand()%8;
		tmpIn[bytesPosition] ^= 1<<bitPosition;
		cout << "byte:" << bytesPosition << " bit:" << bitPosition << endl;

		rs.getErrorsAndDecode(tmpIn, inputLength);

		for(size_t i = 0; i < outputLength; i++) {
			EXPECT_EQ(tmpIn[i], outTruth[i]) << "Reed-Solomon correction differ on position: " << i;
		}
	}

}

//#endif
