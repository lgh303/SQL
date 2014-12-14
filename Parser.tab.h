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
     TBS = 269,
     INDEX = 270,
     DESC = 271,
     NOT = 272,
     NUL = 273,
     PRIMARY = 274,
     FOREIGN = 275,
     KEY = 276,
     CHECK = 277,
     REFER = 278,
     INS_INTO = 279,
     VALUES = 280,
     DELETE = 281,
     WHERE = 282,
     UPDATE = 283,
     SET = 284,
     SELECT = 285,
     FROM = 286,
     LIKE = 287,
     AND = 288,
     OR = 289,
     SUM = 290,
     AVG = 291,
     MAX = 292,
     MIN = 293,
     GRP_BY = 294,
     INT = 295,
     CHAR = 296,
     VCHAR = 297
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


