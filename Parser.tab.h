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
     IS = 273,
     NUL = 274,
     PRIMARY = 275,
     FOREIGN = 276,
     KEY = 277,
     CHECK = 278,
     REFER = 279,
     INS_INTO = 280,
     VALUES = 281,
     DELETE = 282,
     WHERE = 283,
     UPDATE = 284,
     SET = 285,
     SELECT = 286,
     FROM = 287,
     LIKE = 288,
     AND = 289,
     OR = 290,
     SUM = 291,
     AVG = 292,
     MAX = 293,
     MIN = 294,
     GRP_BY = 295,
     INT = 296,
     CHAR = 297,
     VCHAR = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


