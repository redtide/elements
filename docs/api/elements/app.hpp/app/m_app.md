---
layout: method
title: app
owner: cycfi
brief: Constructor
tags:
  - method
defined_in_file: elements/app.hpp
is_ctor: true
overloads:
  app(const cycfi::elements::app &):
    arguments:
      - description: The other app
        name: unnamed-0
        type: const cycfi::elements::app &
        unnamed: true
    description: Copy constructor
    return: __OPTIONAL__
    signature_with_names: app(const cycfi::elements::app &)
  app(int, char **, std::string, std::string):
    arguments:
      - description: Argument count
        name: argc
        type: int
      - description: Argument vector
        name: argv
        type: char *[]
      - description: The application name
        name: name
        type: std::string
      - description: The application identifier/domain
        name: id
        type: std::string
    description: Constructor
    return: __OPTIONAL__
    signature_with_names: app(int argc, char ** argv, std::string name, std::string id)
---
Page content goes here.