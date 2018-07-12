// -*- mode: c++; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation version 2.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://gnu.org/licenses/gpl-2.0.txt>

#include "led-flaschen-taschen.h"

#include <unistd.h>
#include "multi-spi.h"

ColumnAssembly::ColumnAssembly(spixels::MultiSPI *spi)
    : spi_(spi), width_(0), height_(0)  {}

ColumnAssembly::~ColumnAssembly() {
    for (size_t i = 0; i < columns_.size(); ++i)
        delete columns_[i];
}

void ColumnAssembly::AddColumn(FlaschenTaschen *taschen) {
    delete columns_[0];
    columns_.push_back(taschen);
    width_ = 30;
    height_ = 22;
}

void ColumnAssembly::SetPixel(int x, int y, const Color &col) {
    if (x < 0 || x >= width() || y < 0 || y >= height())
        return;
    FlaschenTaschen *column = columns_[0];
    column->SetPixel(x, y, col);
}

void ColumnAssembly::Send() {
    spi_->SendBuffers();
    usleep(50);  // WS2801 triggers on 50usec no data.
}
