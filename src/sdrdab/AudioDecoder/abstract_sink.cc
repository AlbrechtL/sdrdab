/*
 * @class AbstractSink
 *
 * @author: Kacper Patro patro.kacper@gmail.com
 * @date May 13, 2015
 *
 * @version 1.0 beta
 * @copyright Copyright (c) 2015 Kacper Patro
 * @par License
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "abstract_sink.h"
#include <string.h>

AbstractSink::~AbstractSink() {
}

AbstractSink::AbstractSink() {
}

bool AbstractSink::operator ==(const AbstractSink &other) const {
    return !strcmp(name(), other.name());
}
