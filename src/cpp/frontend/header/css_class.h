/**
 *       \file       css_class.h
 *
 *       \brief      Map for CSS classes used for form elements and other
 *                   styling
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, simakmandeep@gmail.com
 *       \license    GNU General Public License Version 2\n
 *       \copyright  Copyright (c) 2014, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */

#ifndef  CSS_CLASS_H
#define  CSS_CLASS_H

#include <iostream>
#include <map>
#include <string>

/**
 *  Defining css map for CSS classes used for form elements and other
 *  styling
 */

namespace css
{
    std::map<string, string> className = 
    {

        /* CSS Class Names */

        {"text", "theFormTextInput"},
        {"button", "theFormButton"},
        {"label", "theLabel"},
        {"error", "theError"}
    };
}

#endif   /* #ifndef CSS-CLASS_H */

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */ 
