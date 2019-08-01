from conans import ConanFile, CMake
import os

class KabosuConan(ConanFile):
    name = "kabosu"
    version = "0.2"
    license = "BSD 3-clause"
    author = "Zachary Stiers"
    url = "https://github.com/zstiers/kabosu"
    description = 'Platform agnostic runtime dynamic library loader'
    settings = "os", "compiler", "build_type", "arch"
    options = { "shared": [True, False] }
    default_options = "shared=True"
    generators = "cmake"
    scm = {
        "type": "git",
        "url": "auto",
        "revision": "auto"
    }

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h"  , dst="include", src="inc", keep_path=True)
        self.copy("*.a"  , dst="lib", src="", keep_path=False)
        self.copy("*.so" , dst="lib", src="", keep_path=False)
        self.copy("*.lib", dst="lib", src="", keep_path=False)
        self.copy("*.pdb", dst="lib", src="", keep_path=False)
        self.copy("*.dll", dst="bin", src="", keep_path=False)
        
    def package_info(self):
        self.cpp_info.libs = ["kabosu"]
