//  $Id$
//
//  Pingus - A free Lemmings clone
//  Copyright (C) 2002 Ingo Ruhnke <grumbel@gmx.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "construo.hxx"
#include "zoom_graphic_context.hxx"
#include "gui_file_manager.hxx"

GUIFileManager::GUIFileManager ()
{
  current_directory = new GUIDirectory ("/examples/");
  directories["/"] = current_directory;
}

GUIFileManager::~GUIFileManager ()
{
  
}

void
GUIFileManager::draw ()
{
  current_directory->draw (graphic_context);
}

/* EOF */