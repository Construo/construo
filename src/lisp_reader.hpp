// Construo - A wire-frame construction game
// Copyright (C) 2002 Ingo Ruhnke <grumbel@gmail.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_LISP_READER_HPP
#define HEADER_LISP_READER_HPP

extern "C" {
#include <lispreader.h>
}

#include "vector2d.hpp"

/** */
class LispReader
{
private:
  lisp_object_t* lst;

  lisp_object_t* search_for(const char* name);
public:
  /** cur == ((pos 1 2 3) (id 12 3 4)...) */
  LispReader (lisp_object_t* l);

  bool read_vector (const char* name, Vector2d* vec);
  bool read_int (const char* name, int* i);
  bool read_float (const char* name, float* f);
  bool read_bool (const char* name, bool* b);
};

#endif

/* EOF */
