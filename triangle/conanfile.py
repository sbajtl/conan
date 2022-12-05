from conans import ConanFile, CMake, tools


class TriangleConan(ConanFile):
    name = "triangle"
    version = "1.6"
    license = "<Put the package license here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of Triangle here>"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"

    def source(self):
        self.run("rsync -avr --exclude build ~/triangle .")

    def build(self):
        cmake = self.configure_cmake()
        cmake.build()

    def configure_cmake(self):
        cmake = CMake(self)
        cmake.configure(source_folder="triangle")
        return cmake

    def package(self):
        cmake = self.configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["triangle"]

