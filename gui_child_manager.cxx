//  $Id$
//
//  Construo - A wire-frame construction gamee
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

#include <algorithm>
#include "graphic_context.hxx"
#include "colors.hxx"
#include "gui_child_manager.hxx"

GUIChildManager::GUIChildManager (int x, int y, int width, int height)
  : GUIComponent (x, y, width, height)
{
  current_component = 0;
}

GUIChildManager::~GUIChildManager ()
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      delete *i;
    }
}

void
GUIChildManager::add (GUIComponent* comp)
{
  components.push_back(comp);
}

void
GUIChildManager::remove (GUIComponent* comp)
{
  components.erase(std::remove(components.begin(), components.end(), comp), components.end());
}

void
GUIChildManager::draw (GraphicContext* parent_gc)
{
  gc.set_parent_gc (parent_gc);
  gc.set_offset (x_pos, y_pos);
  
  parent_gc->draw_fill_rect (x_pos, y_pos,
                             x_pos + width, y_pos + height, 
                             Colors::button_bg_passive);
  parent_gc->draw_rect (x_pos, y_pos,
                        x_pos + width, y_pos + height, 
                        Colors::button_fg_passive);

  parent_gc->draw_fill_rect (x_pos, y_pos,
                             x_pos + width, y_pos, 
                             Colors::button_bg_hover);

  parent_gc->draw_rect (x_pos, y_pos,
                        x_pos + width, y_pos, 
                        Colors::button_fg_passive);

  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      (*i)->draw (&gc);
    }
}

void
GUIChildManager::on_primary_button_press (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          (*i)->on_primary_button_press (x - x_pos, y - y_pos);
          return;
        }
    }
}

void
GUIChildManager::on_primary_button_release (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          (*i)->on_primary_button_release (x - x_pos, y - y_pos);
          return;
        }
    }
}

void
GUIChildManager::on_secondary_button_press (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          (*i)->on_secondary_button_press (x - x_pos, y - y_pos);
          return;
        }
    }
}

void
GUIChildManager::on_secondary_button_release (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          (*i)->on_secondary_button_release (x - x_pos, y - y_pos);
          return;
        }
    }
}
  
void
GUIChildManager::on_delete_press (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          (*i)->on_delete_press (x - x_pos, y - y_pos);
          return;
        }
    }
}

void
GUIChildManager::on_fix_press (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          (*i)->on_fix_press (x - x_pos, y - y_pos);
          return;
        }
    }
}

void
GUIChildManager::on_mouse_enter ()
{
}

void
GUIChildManager::on_mouse_leave ()
{
}

void
GUIChildManager::wheel_up (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          (*i)->wheel_up (x - x_pos, y - y_pos);
          return;
        }
    }
}

void
GUIChildManager::wheel_down (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          (*i)->wheel_down (x - x_pos, y - y_pos);
          return;
        }
    }
}

void
GUIChildManager::scroll_left ()
{
  /*  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
      {
      if ((*i)->is_at (x - x_pos, y - y_pos))
      {
      (*i)->scroll_left (x - x_pos, y - y_pos);
      return;
      }
      }*/
}

void
GUIChildManager::scroll_right ()
{
  /*
    for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
    if ((*i)->is_at (x - x_pos, y - y_pos))
    {
    (*i)->scroll_right (x - x_pos, y - y_pos);
    return;
    }
    }*/
}

void
GUIChildManager::scroll_up ()
{
  /*  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
      {
      if ((*i)->is_at (x - x_pos, y - y_pos))
      {
      (*i)->scroll_down (x - x_pos, y - y_pos);
      return;
      }
      }*/
}

void
GUIChildManager::scroll_down ()
{
  /*
    for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
    if ((*i)->is_at (x - x_pos, y - y_pos))
    {
    (*i)->scroll_down (x - x_pos, y - y_pos);
    return;
    }
    }*/
}

void
GUIChildManager::on_mouse_move (int x, int y, int of_x, int of_y)
{
  GUIComponent* comp = find_component_at (x, y);
  //std::cout << " MouseMove: " << x << " " << y << " " << comp << std::endl;

  if (comp != current_component)
    {
      if (comp) comp->on_mouse_enter();
      if (current_component) current_component->on_mouse_leave();
      current_component = comp;
    }
  else if (comp)
    comp->on_mouse_move(x, y, of_x, of_y);
}

GUIComponent* 
GUIChildManager::find_component_at (int x, int y)
{
  for (ComponentLst::iterator i = components.begin (); i != components.end (); ++i)
    {
      if ((*i)->is_at (x - x_pos, y - y_pos))
        {
          return *i;
        }
    }
  return 0;
}

/* EOF */