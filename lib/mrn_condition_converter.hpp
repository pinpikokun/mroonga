/* -*- c-basic-offset: 2 -*- */
/*
  Copyright(C) 2013 Kouhei Sutou <kou@clear-code.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef MRN_CONDITION_CONVERTER_HPP_
#define MRN_CONDITION_CONVERTER_HPP_

#include <groonga.h>
#include <mrn_mysql_compat.h>

namespace mrn {
  class ConditionConverter {
  public:
    ConditionConverter(bool is_storage_mode, const Item *where);
    void convert(grn_ctx *ctx, grn_obj *expression);

  private:
    bool is_storage_mode_;
    const Item *where_;

    void convert_equal(grn_ctx *ctx, grn_obj *expression,
                       const Item_func *func_item,
                       grn_obj *column_name, grn_obj *value);
  };
}

#endif /* MRN_CONDITION_CONVERTER_HPP_ */
