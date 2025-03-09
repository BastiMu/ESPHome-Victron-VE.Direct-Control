#include "esphome.h"

std::string bytest2string(std::vector<uint8_t> bytes) {
  std::string res;
  size_t len = bytes.size();
  char buf[5];
  for (size_t i = 0; i < len; i++) {
    // set characters
    if (bytes[i] == 7) {
      res += "\\a";
    } else if (bytes[i] == 8) {
      res += "\\b";
    } else if (bytes[i] == 9) {
      res += "\\t";
    } else if (bytes[i] == 10) {
      res += "\\n";
    } else if (bytes[i] == 11) {
      res += "\\v";
    } else if (bytes[i] == 12) {
      res += "\\f";
    } else if (bytes[i] == 13) {
      res += "\\r";
    } else if (bytes[i] == 27) {
      res += "\\e";
    } else if (bytes[i] == 34) {
      res += "\\\"";
    } else if (bytes[i] == 39) {
      res += "\\'";
    } else if (bytes[i] == 92) {
      res += "\\\\";
    } else if (bytes[i] < 32 || bytes[i] > 127) {
      sprintf(buf, "\\x%02X", bytes[i]);
      res += buf;
    } else {
      res += bytes[i];
    }
  }
  return res;
}

std::string getValueFromBytes(std::vector<uint8_t> bytes) {
  std::string res;
  size_t len = bytes.size();
  bool tab = false;
  char buf[5];
  for (size_t i = 0; i < len; i++) {
    // check if tab is reached
    tab |= bytes[i] == 0x09;
    // continue if tab is not reached yet
    if (!tab) {continue;}
    // set characters
    if (bytes[i] == 7) {
      res += "\\a";
    } else if (bytes[i] == 8) {
      res += "\\b";
    } else if (bytes[i] == 9) {
      //res += "\\t"; // skip tab
    } else if (bytes[i] == 10) {
      //res += "\\n"; // skip newline
    } else if (bytes[i] == 11) {
      res += "\\v";
    } else if (bytes[i] == 12) {
      res += "\\f";
    } else if (bytes[i] == 13) {
      //res += "\\r"; // skip linebreak
    } else if (bytes[i] == 27) {
      res += "\\e";
    } else if (bytes[i] == 34) {
      res += "\\\"";
    } else if (bytes[i] == 39) {
      res += "\\'";
    } else if (bytes[i] == 92) {
      res += "\\\\";
    } else if (bytes[i] < 32 || bytes[i] > 127) {
      sprintf(buf, "\\x%02X", bytes[i]);
      res += buf;
    } else {
      res += bytes[i];
    }
  }
  return res;
}

std::string getFieldFromBytes(std::vector<uint8_t> bytes) {
  std::string res;
  size_t len = bytes.size();
  bool tab = false;
  char buf[5];
  for (size_t i = 0; i < len; i++) {
    // check if tab is reached
    tab |= bytes[i] == 0x09;
    // continue if tab is not reached yet
    if (tab) {continue;}
    // set characters
    if (bytes[i] == 7) {
      res += "\\a";
    } else if (bytes[i] == 8) {
      res += "\\b";
    } else if (bytes[i] == 9) {
      //res += "\\t"; // skip tab
    } else if (bytes[i] == 10) {
      //res += "\\n"; // skip newline
    } else if (bytes[i] == 11) {
      res += "\\v";
    } else if (bytes[i] == 12) {
      res += "\\f";
    } else if (bytes[i] == 13) {
      //res += "\\r"; // skip linebreak
    } else if (bytes[i] == 27) {
      res += "\\e";
    } else if (bytes[i] == 34) {
      res += "\\\"";
    } else if (bytes[i] == 39) {
      res += "\\'";
    } else if (bytes[i] == 92) {
      res += "\\\\";
    } else if (bytes[i] < 32 || bytes[i] > 127) {
      sprintf(buf, "\\x%02X", bytes[i]);
      res += buf;
    } else {
      res += bytes[i];
    }
  }
  return res;
}

std::vector<unsigned char> getPayload(uint8_t val) {
  uint8_t val0 = val / 16;
  uint8_t val1 = val % 16;
  uint8_t payload0 = val0 < 10 ? val0 + 0x30 : val0 + 0x37;
  uint8_t payload1 = val1 < 10 ? val1 + 0x30 : val1 + 0x37;
  std::vector<unsigned char> message = {static_cast<unsigned char>(payload0), static_cast<unsigned char>(payload1)};
  return message;
}
