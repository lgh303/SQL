/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     IDENTIFIER = 259,
     LITERAL = 260,
     ENDLINE = 261,
     QUIT = 262,
     CREATE = 263,
     DB = 264,
     DROP = 265,
     USE = 266,
     SHOW = 267,
     TB = 268,
     INDEX = 269,
     DESC = 270,
     NOT = 271,
     NUL = 272,
     PRIMARY = 273,
     FOREIGN = 274,
     KEY = 275,
     CHECK = 276,
     REFER = 277,
     INS_INTO = 278,
     VALUES = 279,
     DELETE = 280,
     WHERE = 281,
     UPDATE = 282,
     SET = 283,
     SELECT = 284,
     FROM = 285,
     LIKE = 286,
     AND = 287,
     OR = 288,
     SUM = 289,
     AVG = 290,
     MAX = 291,
     MIN = 292,
     GRP_BY = 293,
     INT = 294,
     CHAR = 295,
     VCHAR = 296
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


