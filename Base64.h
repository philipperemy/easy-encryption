#ifndef BASE64_H
#define BASE64_H
///////////////////////////////////////////////////////////////////////
// Base64.h - declares class that encodes binary data into a string  //
// ver 2.0    and decodes the string back to binary data             //
//                                                                   //
// Language:    Visual C++, ver 7.1                                  //
// Platfrom:    Dell Dimension 8300, Windows XP, SP1                 //
// Application: CSE687 - Object Oriented Design, Spring 2004         //
// Author:      Jim Fawcett, CST 2-187, Syracuse University          //
//              (315) 443-3948, jfawcett@twcny.rr.com                //
///////////////////////////////////////////////////////////////////////
// based on:                                                         //
//*********************************************************************
//* C_Base64 - a simple base64 encoder and decoder.
//*
//*     Copyright (c) 1999, Bob Withers - bwit@pobox.com
//*
//* This code may be freely used for any purpose, either personal
//* or commercial, provided the authors copyright notice remains
//* intact.
//*********************************************************************
/*
 *  Module Operation:
 *  =================
 *  The Base64 class provides static encode and decode functions that
 *  use base64 encoding to render a vector of bytes into a std::string
 *  of ASCII characters and back again.  This supports the transmission
 *  of binary data as XML messages.
 *
 *  Public Interface:
 *  =================
 *  std::vector<char> vBytes;
 *  // vBytes filed, perhaps from a file
 *  std::string encodedString = Base64::encode(vBytes);
 *  // do something with string, perhaps send as XML message
 *  std::vector<char> vDecodedBytes = Base64::decode(encodedMsg);
 *
 *  Build Process:
 *  ==============
 *  Required files - Base64.h, Base64.cpp
 *
 *  compiler command - cl /EHsc /DTEST_BASE64 Base64.cpp
 *
 *  Maintenance History:
 *  ====================
 *  ver 1.0 : 25 Mar 04
 *  - first release, based on code by Bob Withers
 *  ver 2.0 : 20 Apr 04
 *  - changed interface from std::strings for both input and output
 *    to std::vector<char> for binary data and std::string for its
 *    endcoding.  Test stub shows how to use this to encode binary
 *    files.
 *
 *  Planned Modifications:
 *  ======================
 *  - add functions to support chunking of large files
 */

//
#include <string>
#include <vector>

class Base64
{
public:
  static std::string encode(const std::vector<char>& data);
  static std::vector<char> decode(const std::string& data);
  static std::string encodeFromFile(const std::string& inFileName);
  static void decodeToFile(
    const std::string& outFileName, const std::string& encodedString
  );
};

#endif
