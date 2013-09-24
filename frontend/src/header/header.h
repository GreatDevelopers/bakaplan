/**
 *
 *       \file       header.h
 *
 *       \brief      Header file for including commom headerfiles.
 *
 *       \version    0.8
 *       \date       Thursday 06 June 2013 09:29:59  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com\n
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <ctime>
#include <exception>

/* for using multi-dimentional array */
#include <boost/multi_array.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <cassert>

/* Using namespaces */
using namespace std;
using namespace boost::algorithm;

/*
 *  Typedef variables for using vector definiton
 */

typedef vector<string> STRING_VEC;
typedef vector<vector<string> > STRING_2DVEC;
typedef vector<vector<vector<string> > > STRING_3DVEC;
typedef vector<vector<vector<vector<string> > > > STRING_4DVEC;
typedef vector<vector<vector<int> > > INT_3DVEC;
typedef vector<vector<int> > INT_2DVEC;
typedef vector<int> INT_VEC;

#endif
