ACLOCAL_AMFLAGS= -I m4
EXTRA_DIST=\
	LICENSE

dist_man8_MANS=\
	doc/usbguard-daemon.roff

dist_man5_MANS=\
	doc/usbguard-daemon.conf.roff \
	doc/usbguard-rules.conf.roff

AM_CPPFLAGS=\
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/src/Library

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libusbguard.pc

lib_LTLIBRARIES=\
	libusbguard.la

libusbguard_la_CPPFLAGS=\
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/src/Library \
	-I$(top_srcdir)/src/Library/RuleParser \
	@qb_CFLAGS@ \
	@json_CFLAGS@ \
	@spdlog_CFLAGS@

libusbguard_la_LDFLAGS=\
	-no-undefined \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

libusbguard_la_LIBADD=\
	@qb_LIBS@ \
	@spdlog_LIBS@ \
	@json_LIBS@

libusbguard_la_SOURCES=\
	src/Library/ConfigFile.cpp \
	src/Library/ConfigFilePrivate.cpp \
	src/Library/ConfigFilePrivate.hpp \
	src/Library/IPCClient.cpp \
	src/Library/IPCClientPrivate.hpp \
	src/Library/IPCClientPrivate.cpp \
	src/Library/USB.cpp \
	src/Library/Rule.cpp \
	src/Library/RuleParser.cpp \
	src/Library/RuleParser.hpp \
	src/Library/RulePrivate.cpp \
	src/Library/RulePrivate.hpp \
	src/Library/RuleSet.cpp \
	src/Library/RuleSetPrivate.cpp \
	src/Library/RuleSetPrivate.hpp \
	src/Library/RuleParser/Lexer-configuration.hpp \
	src/Library/RuleParser/Lexer.cpp \
	src/Library/RuleParser/Lexer.hpp \
	src/Library/RuleParser/Lexer-token.hpp \
	src/Library/RuleParser/Lexer-token_ids.hpp \
	src/Library/RuleParser/Parser.h \
	src/Common/Thread.hpp \
	src/Common/JSON.hpp \
	src/Common/ByteOrder.hpp \
	src/Library/Typedefs.cpp \
	src/Common/Utility.hpp \
	src/Common/Utility.cpp

pkginclude_HEADERS=\
	src/Library/ConfigFile.hpp \
	src/Library/IPC.hpp \
	src/Library/IPCClient.hpp \
	src/Library/USB.hpp \
	src/Library/Rule.hpp \
	src/Library/RuleSet.hpp \
	src/Library/Typedefs.hpp

EXTRA_DIST +=\
	src/Library/RuleParser/Lexer.qx \
	src/Library/RuleParser/Parser.y \
	src/Library/RuleParser/Parser.c \
	src/Library/RuleParser/quex \
	src/Library/RuleParser/README.md

sbin_PROGRAMS=\
	usbguard-daemon

usbguard_daemon_SOURCES=\
	src/Daemon/Daemon.cpp \
	src/Daemon/Daemon.hpp \
	src/Daemon/Exceptions.hpp \
	src/Daemon/SysIO.cpp \
	src/Daemon/SysIO.hpp \
	src/Daemon/Device.hpp \
	src/Daemon/Device.cpp \
	src/Daemon/DeviceManager.hpp \
	src/Daemon/DeviceManager.cpp \
	src/Daemon/LinuxDeviceManager.hpp \
	src/Daemon/LinuxDeviceManager.cpp \
	src/Daemon/main.cpp \
	src/Common/Logging.cpp \
	src/Common/Logging.hpp \
	src/Common/CCBQueue.hpp

usbguard_daemon_CPPFLAGS=\
	$(AM_CPPFLAGS) \
	@udev_CFLAGS@ \
	@sodium_CFLAGS@ \
	@spdlog_CFLAGS@ \
	@json_CFLAGS@

usbguard_daemon_LDADD=\
	$(top_builddir)/libusbguard.la \
	@udev_LIBS@ \
	@sodium_LIBS@ \
	@spdlog_LIBS@ \
	@json_LIBS@

EXTRA_DIST +=\
	README.md \
	src/ThirdParty/spdlog \
	src/ThirdParty/json/src/json.hpp
