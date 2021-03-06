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
     DBS = 265,
     DROP = 266,
     USE = 267,
     SHOW = 268,
     TB = 269,
     TBS = 270,
     INDEX = 271,
     DESC = 272,
     NOT = 273,
     IS = 274,
     NUL = 275,
     IN = 276,
     PRIMARY = 277,
     FOREIGN = 278,
     KEY = 279,
     CHECK = 280,
     REFER = 281,
     INS_INTO = 282,
     VALUES = 283,
     DELETE = 284,
     WHERE = 285,
     UPDATE = 286,
     SET = 287,
     SELECT = 288,
     FROM = 289,
     LIKE = 290,
     AND = 291,
     OR = 292,
     SUM = 293,
     AVG = 294,
     MAX = 295,
     MIN = 296,
     GRP_BY = 297,
     INT = 298,
     CHAR = 299,
     VCHAR = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


