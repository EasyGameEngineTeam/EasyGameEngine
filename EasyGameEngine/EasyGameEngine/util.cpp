#include "util.h"

namespace EasyGame {
	DATA(std::string, ID, ResourceLocation)
	DATA(std::string, Path, ResourceLocation)
	DATA(ResourceLocation::TYPE::Type, Type, ResourceLocation)


	ResourceLocation::ResourceLocation(std::string ID, std::string Path, TYPE::Type Type) {
		this->ID = ID;
		this->Path = Path;
		this->Type = Type;
	}

	std::string ResourceLocation::toString() {
		return ID + "." + Path + "::" + TYPE::toString(Type);
	}

	std::string ResourceLocation::toPath() {
		return "./assets/" + ID + "/" + TYPE::toString(Type) + "/" + Path;
	}

	std::string ResourceLocation::TYPE::toString(Type type) {
		switch (type) {
		case DATA:
			return "data";
		case RESOURCE:
			return "resource";
		case SOURCE:
			return "source";
		case CONFIG:
			return "config";
		case SAVE:
			return "save";
		default:
			return "unknown";
		}
	}


	ResourceLocation createLocation(std::string ID, std::string Path, ResourceLocation::TYPE::Type Type) {
		return ResourceLocation(ID, Path, Type);
	}
}