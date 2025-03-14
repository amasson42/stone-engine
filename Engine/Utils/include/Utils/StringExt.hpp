// Copyright 2024 Stone-Engine

#pragma once

#include <string>

bool string_ends_with(const std::string &str, const std::string &suffix);
bool string_starts_with(const std::string &str, const std::string &prefix);
bool string_contains_non_printable(const std::string &str);
std::string int_to_hex(unsigned char c);
std::string escape_string(const std::string &str);
