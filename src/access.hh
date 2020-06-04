

#ifndef CACHE_ACCESS
#define CACHE_ACCESS

#include <cstdint>
#include <string>
#include <tuple>
#include <vector>

class CacheAccess {
 public:
  CacheAccess(unsigned batch_size, std::string trace_file);
  ~CacheAccess() = default;

  std::tuple<uint64_t, uint32_t, uint8_t> get_access();
  unsigned fetch_access_batch();
  unsigned parse_input_file();

 private:
  std::vector<uint64_t> addresses;

  std::vector<uint32_t> instructions;

  std::vector<uint8_t> types;

  const std::string f_name;

  uint32_t current_access = 0;

  uint32_t file_position = 0;

  uint64_t access = 0;
};

#endif
