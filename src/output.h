/* Output the generated parsing program for bison,

   Copyright (C) 2000-2003, 2006-2007, 2009-2015, 2018-2019 Free
   Software Foundation, Inc.

   This file is part of Bison, the GNU Compiler Compiler.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef OUTPUT_H_
# define OUTPUT_H_

/* Output the parsing tables and the parser code to FTABLE.  */
void output (void);

/* Where our data files are installed.  */
char const *pkgdatadir (void);

#endif /* !OUTPUT_H_ */
