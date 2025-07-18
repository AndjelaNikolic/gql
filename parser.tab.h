
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
     QUERY = 258,
     RESULT_OF_QUERY = 259,
     EXEC = 260,
     IF = 261,
     FOR = 262,
     IN = 263,
     EMPTY = 264,
     URL_EXISTS = 265,
     NOT_EMPTY = 266,
     BEGIN_KW = 267,
     END_KW = 268,
     SET_UNION = 269,
     SET_DIFFERENCE = 270,
     SET_INTERSECTION = 271,
     POW = 272,
     PLUS = 273,
     MINUS = 274,
     MULT = 275,
     OR = 276,
     LT = 277,
     GT = 278,
     LBRACKET = 279,
     RBRACKET = 280,
     LPAREN = 281,
     RPAREN = 282,
     COMMA = 283,
     SEMICOLON = 284,
     COLON = 285,
     EQUALS = 286,
     MINUS_EQ = 287,
     ID = 288,
     STRING = 289,
     UMINUS = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 19 "parser.y"

    char *str;
    struct ASTNode *ast;



/* Line 1676 of yacc.c  */
#line 94 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


