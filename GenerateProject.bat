@echo off
del Grape.sln
del Grape\Grape.vcxproj
del Grape\Grape.vcxproj.user
del Grape\Grape.vcxproj.filters
del Sandbox\Sandbox.vcxproj
del Sandbox\Sandbox.vcxproj.user
del Sandbox\Sandbox.vcxproj.filters
External\bin\premake5.exe vs2019
pause