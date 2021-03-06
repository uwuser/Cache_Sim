
#include <cstdint>
#include "access.hh"
#include "cache_config.pb.h"
#include "data_cache.hh"

// Top-level simulation class
class CacheSim {
 public:
  // Constructors/Destructors
  CacheSim(CacheConfig config);
  ~CacheSim();

  // Simulator functionality methods
  // Run the simulation
  void run();

 private:
  // Cache Level
  // Needs to be extended to a list later on (multi-level caches)
  CacheLevel CL;

  // Cache access
  CacheAccess CA;

  // Number of instructions executed
  uint64_t instructions = 0;

  // Number of cycles executed
  uint64_t cycles = 0;
};
