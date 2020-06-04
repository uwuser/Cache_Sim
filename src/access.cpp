
#include "access.hh"
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

CacheAccess::CacheAccess(uint32_t batch_size, std::string trace_file)
    : f_name(trace_file) {
  // Resize all the vectors
  addresses.resize(batch_size);
  instructions.resize(batch_size);
  types.resize(batch_size);
}

std::tuple<uint64_t, uint32_t, uint8_t> CacheAccess::get_access() {
  // Make the tuple
  auto ret_val =
      std::make_tuple(addresses[current_access], instructions[current_access],
                      types[current_access]);

  // Increment the current access
  current_access++;

  return ret_val;
}
uint32_t CacheAccess::fetch_access_batch() {
  // Reset the access number we're on
  current_access = 0;

  return parse_input_file();
}

uint32_t CacheAccess::parse_input_file() {
  // Open the file and seek to the last position
  std::ifstream file(f_name);
  file.seekg(file_position);

  // Read in one batch (at most)
  size_t i;
  for (i = 0; i < addresses.size(); i++) {
    std::string line;
    if (std::getline(file, line)) {
      std::stringstream ss(line);

      std::string sink;
      std::string addr_string;
      uint8_t type;
      int insns;

      // Get the values
      ss >> sink;
      ss >> type;
      ss >> addr_string;
      ss >> insns;

      uint64_t addr = std::stoull(addr_string, nullptr, 16);

      // Fill in the values
      addresses[i] = addr;
      instructions[i] = insns;
      types[i] = type;
    } else {
      break;
    }
  }

  file_position = file.tellg();
  return i;
}
