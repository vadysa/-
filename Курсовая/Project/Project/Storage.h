#pragma once
#include <vector>
#include "Container.h"
#include "OperatingSystem.h"
#include "Utility.h"
#include "DinamicVector.h"
#include "DeviceDrivers.h"
#include "GeneralPurposePrograms.h"
#include "SpecialPurposePrograms.h"
#include "ProgrammingSystems.h"
#include "ApplicationSoftware.h"
#include "SystemSoftware.h"
/*
	Класс хранящий статические переменные всех контейнеров
*/
class Storage
{
public:
	// Контейнер с указателями на классы для части B
	static Container<ISoftware*> StaticContainer;
	
	// Контейнер с объектами каждого типа для части C
	static DinamicVector <OperatingSystems> OperatingSystem;
	static DinamicVector <Utility> Utilities;
	static DinamicVector <DeviceDrivers> DeviceDriver;
	static DinamicVector <GeneralPurposePrograms> GeneralPurposeProgram;
	static DinamicVector <SpecialPurposePrograms> SpecialPurposeProgram;
	static DinamicVector <ProgrammingSystems> ProgrammingSystem;
	static DinamicVector <SystemSoftware> SystemSoftwares;
	static DinamicVector <ApplicationSoftware> ApplicationSoftwares;
};


Container<ISoftware*> Storage::StaticContainer;
DinamicVector<OperatingSystems> Storage::OperatingSystem;
DinamicVector<Utility> Storage::Utilities;
DinamicVector<DeviceDrivers> Storage::DeviceDriver;
DinamicVector<GeneralPurposePrograms> Storage::GeneralPurposeProgram;
DinamicVector<SpecialPurposePrograms> Storage::SpecialPurposeProgram;
DinamicVector<ProgrammingSystems> Storage::ProgrammingSystem;
DinamicVector<SystemSoftware> Storage::SystemSoftwares;
DinamicVector<ApplicationSoftware> Storage::ApplicationSoftwares;

