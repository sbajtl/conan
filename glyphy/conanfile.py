from conans import ConanFile, CMake


class GlyphyConan(ConanFile):
    name = "glyphy"
    version = "1.0"
    license = "http://www.apache.org/licenses/LICENSE-2.0"
    url = "https://github.com/behdad/glyphy"
    description = "GLyphy is a signed-distance-field (SDF) text renderer using OpenGL ES2 shading language."
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = { "shared": False, "freetype:with_brotli": False }
    generators = "cmake", "cmake_find_package"

    def source(self):
        self.run("rsync -avr --exclude build ~/glyphy .")

    def requirements(self):
        self.requires.add("freetype/2.12.1")

    def build(self):
        cmake = self.configure_cmake()
        cmake.build()

    def configure_cmake(self):
        cmake = CMake(self)
        cmake.configure(source_folder="glyphy")
        return cmake

    def package(self):
        cmake = self.configure_cmake()
        cmake.install()
        self.copy("FindGlyphy.cmake", ".", ".")

    def package_info(self):
        self.cpp_info.libs = ["glyphy"]

