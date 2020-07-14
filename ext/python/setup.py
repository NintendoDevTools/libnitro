import glob
from distutils.core import setup, Extension

setup(
    name="libnitro_native",
    ext_modules=[
        Extension('libnitro_native',
                  sources=glob.glob("src/**/*.cpp", recursive=True),
                  include_dirs=["."],
                  language='c++')
    ]
)
