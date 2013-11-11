/**
 *       \file       header.h
 *
 *       \brief      Common header file, includes all required header
 *                   files
 *
 *       \version    0.8
 *       \date       Sunday 31 March 2013 02:00:19  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef HEADER_H
#define HEADER_H

/*
 *  Include global and local header files which are common to all 
 */

#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <climits>
#include <deque>
#include <algorithm>
#include <ctime>
#include <setjmp.h>
#include <hpdf.h>

#include "boost/multi_array.hpp"

#include "filename.h"

using namespace std;

/*
 *   Typedef for boost:multi_array
 */
//typedef boost::multi_array<int, 3> int3D;
//typedef boost::multi_array<string, 1> string1D;

typedef vector<string> STRING_VEC;
typedef vector<vector<string> > STRING_2DVEC;
typedef vector<vector<vector<string> > > STRING_3DVEC;
typedef vector<vector<vector<vector<string> > > > STRING_4DVEC;
typedef vector<vector<vector<int> > > INT_3DVEC;
typedef vector<vector<int> > INT_2DVEC;
typedef vector<int> INT_VEC;

#endif
