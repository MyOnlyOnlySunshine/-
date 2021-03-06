#############################################################################
# Makefile for building: modelview1.app/Contents/MacOS/modelview1
# Generated by qmake (3.0) (Qt 5.7.1)
# Project:  ../modelview1/modelview1.pro
# Template: app
# Command: /Applications/QT/5.7/ios/bin/qmake -spec macx-ios-clang CONFIG+=iphonesimulator CONFIG+=simulator CONFIG+=qml_debug -spec macx-xcode -o modelview1.xcodeproj/project.pbxproj ../modelview1/modelview1.pro
#############################################################################

MAKEFILE      = project.pbxproj

MOC       = /Applications/QT/5.7/ios/bin/moc
UIC       = /Applications/QT/5.7/ios/bin/uic
LEX       = flex
LEXFLAGS  = 
YACC      = yacc
YACCFLAGS = -d
DEFINES       = -DDARWIN_NO_CARBON -DQT_NO_PRINTER -DQT_NO_PRINTDIALOG -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
INCPATH       = -I../modelview1 -I. -I/Applications/QT/5.7/ios/mkspecs/macx-ios-clang/ios -I/Applications/QT/5.7/ios/include -I/Applications/QT/5.7/ios/include/QtWidgets -I/Applications/QT/5.7/ios/include/QtGui -I/Applications/QT/5.7/ios/include/QtCore -I. -I/Applications/QT/5.7/ios/mkspecs/macx-ios-clang
DEL_FILE  = rm -f
MOVE      = mv -f

preprocess: compilers
clean preprocess_clean: compiler_clean

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compilers:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

