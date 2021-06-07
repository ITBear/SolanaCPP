TEMPLATE = subdirs

os_linux {
	SUBDIRS += \
		./DataModel \
		./ApiClient \
		./LightWalletCore
} else:os_android {
	SUBDIRS += \
		./DataModel \
		./ApiClient \
		./LightWalletCore
} else:os_ios {
	SUBDIRS += \
		./DataModel \
		./ApiClient \
		./LightWalletCore
} else:os_windows {
	SUBDIRS += \
		./DataModel \
		./ApiClient \
		./LightWalletCore
} else:os_macx {
	SUBDIRS += \
		./DataModel \
		./ApiClient \
		./LightWalletCore
} else:os_browser {
	SUBDIRS += \
		./LightWalletCore \
		./LightWalletCoreWasm
} else {
	error(Unknown OS. Set CONFIG+=... one of values: os_linux, os_android, os_ios, os_windows, os_macx, os_browser)
}

CONFIG += ordered
