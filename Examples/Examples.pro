TEMPLATE = subdirs

os_linux {
	SUBDIRS += \
		./Wallet
} else:os_android {
	SUBDIRS += \
		./Wallet
} else:os_ios {
	SUBDIRS += \
		./Wallet
} else:os_windows {
	SUBDIRS += \
		./Wallet
} else:os_macx {
	SUBDIRS += \
		./Wallet
} else:os_browser {
	SUBDIRS +=
} else {
	error(Unknown OS. Set CONFIG+=... one of values: os_linux, os_android, os_ios, os_windows, os_macx, os_browser)
}

CONFIG += ordered
