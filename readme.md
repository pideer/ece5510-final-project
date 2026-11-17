# setup
you will need a windows machine with a NVIDIA GPU

1. **msvc**. Install Visual Studio with "Desktop Development with C++" and it should install msvc
2. **Cuda Toolkit**. after installing VS, install the cuda toolkit by downloading [this](https://developer.nvidia.com/cuda-downloads). we use 13.5
3. **confirm** by opening "x64 Native Tools Command Prompt" and ensuring `nvcc --version` and `nvidia-smi` return expected values.
4. install python

## file organization
- `/src` will have cpp files
- `/test` will have test results and input files for run.py
- `run.py` is the entrypoint for bulk and automated testing. `/src/main.cpp` is the program's actual entrypoint

# run
- build with `cmake -S . -B build` and then `cmake --build build --config Release`
- run experiments with `run.py`


# assignment details
**Lock-Free Synchronization on GPUs**

**Objective & Approach:** GPUs run thousands of threads in groups of 32 (warps). Spin locks that work well on CPUs (Ch7/spin-locks) can deadlock or perform poorly on a GPU when threads in the same warp contend. Since NVIDIA's Volta architecture, threads within a warp are scheduled independently, which changes which locking patterns are safe. Lock-free designs built on atomic compare-and-swap avoid deadlock but face high contention. Students should implement a concurrent hash table in CUDA, building on Ch13/hashing. They should implement two versions. The first is a dynamic chained table in the style of the slab hash, which supports concurrent inserts, deletes, and lookups. The second is a bucketed cuckoo table in the style of BGHT, a recent family of high-performance GPU hash tables. Both designs use warp-cooperative techniques, in which the threads of a warp jointly perform one operation. Students should also implement a GPU spin lock and show how warp-level contention affects it.

**Evaluation:** The baselines are a lock-based GPU hash table and a lock-free CPU hash table (Ch13/hashing) running on all CPU cores. Students should measure insert and lookup throughput in millions of operations per second. They should vary load factor, batch size, and the mix of inserts and lookups. They should also report the average number of probes per operation, which recent work shows is the main predictor of GPU hash-table performance. A secondary experiment measures the effect of warp-cooperative execution compared with one thread per operation.

**Scoping:** GPU debugging is slow, so teams should first build a simple open-addressing table with one thread per operation and verify it against a CPU reference on every run. Warp-cooperative execution and the slab-style dynamic table come next. The cuckoo table and the GPU spin lock are stretch goals. Students should confirm GPU access on ARC (or another GPU) in the first week, before committing to this topic.

## addressables
1. Your two versions differ in table design (chained vs. cuckoo), not synchronization, so they can’t isolate lock-based vs. lock-free. Implement both a lock-based and a lock-free variant of each design with the same memory layout, and decide early which variants are core vs. stretch.
2. For the chained table, device-side malloc is slow and serializes. Use a pre-allocated pool or slab allocator.
3. Lock-free cuckoo insertion (moving keys during eviction) is the hardest part of this design. If it proves too difficult, keep cuckoo lock-based in the core and make lock-free cuckoo a stretch goal.
4. Add baselines: cuCollections and BGHT as GPU references, and a CPU hash table as a cross-platform point.
5. Define “contention” concretely (e.g., CAS failures/retries per operation and their spread across warps), and state whether batch timing includes host–device transfer.
6. Validate every run against a sequential CPU reference.

## readings
- [A dynamic hash table for the GPU.](https://arxiv.org/pdf/1710.11246) Saman Ashkiani, Martin Farach-Colton, and John D. Owens. 2018. 
- [Analyzing and implementing GPU hash tables.](https://virginiatech.primo.exlibrisgroup.com/permalink/01VT_INST/usm3rc/alma991013825489208646) Muhammad A. Awad, Saman Ashkiani, Serban D. Porumbescu, Martín Farach-Colton, and John D. Owens. 2023.


## task list
1. 