TEMPLATE = subdirs

os_linux {
	SUBDIRS += \
		./Core \
		./Examples
} else:os_android {
	SUBDIRS += \
		./Core \
		./Examples
} else:os_ios {
	SUBDIRS += \
		./Core \
		./Examples
} else:os_windows {
	SUBDIRS += \
		./Core \
		./Examples
} else:os_macx {
	SUBDIRS += \
		./Core \
		./Examples
} else:os_browser {
	SUBDIRS += \
		./Core \
		./Examples
} else {
	error(Unknown OS. Set CONFIG+=... one of values: os_linux, os_android, os_ios, os_windows, os_macx, os_browser)
}

CONFIG += ordered
