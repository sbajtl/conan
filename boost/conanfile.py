from conans import ConanFile, CMake

class BoostImportConan(ConanFile):
   settings = "os", "compiler", "build_type", "arch"
   requires = "boost/1.80.0"
   generators = "cmake", "cmake_find_package"
   default_options = {
     "boost:shared": False,
     "boost:without_math": True,
     "boost:without_context": True,
     "boost:without_contract": True,
     "boost:without_coroutine": True,
     "boost:without_fiber": True,
     "boost:without_graph": True,
     "boost:without_graph_parallel": True,
     "boost:without_json": True,
     "boost:without_locale": True,
     "boost:without_log": True,
     "boost:without_math": True,
     "boost:without_program_options": True,
     "boost:without_python": True,
     "boost:without_serialization": True,
     "boost:without_stacktrace": True,
     "boost:without_wave": True,
     "boost:without_nowide": True
   }


