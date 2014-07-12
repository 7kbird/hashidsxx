#pragma once

#include <string>
#include <vector>

#define DEFAULT_ALPHABET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"

namespace hashidsxx {

class Hashids {
private:
  /**
   *  The salt that will be used to generate the hashes
   */
  const std::string _salt;

  /**
   *  The alphabet that will be used to generate the hashes
   */
  std::string _alphabet;

  /**
   *  Minimum length of the hash, 0 means that there's not minimum
   */
  const unsigned int _min_length;

  std::string _separators;
  std::string _guards;

public:
  Hashids(const std::string &salt = "", const std::string alphabet = DEFAULT_ALPHABET, unsigned int min_length = 0);

  Hashids(const std::string &salt, unsigned int min_length) : Hashids(salt, DEFAULT_ALPHABET, min_length) {};

  std::string encrypt(const std::vector<uint32_t> &input) const;

  std::vector<uint32_t> decrypt(const std::string &input) const;

private:
  std::string& _reorder(std::string &input, const std::string &salt) const;
  std::string _reorder_norewrite(const std::string &input, const std::string &salt) const;
  std::string _hash(uint32_t number, const std::string &alphabet) const;
  uint32_t _unhash(const std::string& input, const std::string &alphabet) const;
  void _ensure_length(std::string &output, std::string &alphabet, int values_hash) const;
  std::vector<std::string> _split(const std::string &hash, const std::string &splitters) const;
};

};