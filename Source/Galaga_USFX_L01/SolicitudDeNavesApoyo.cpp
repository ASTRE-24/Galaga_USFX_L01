// Fill out your copyright notice in the Description page of Project Settings.


#include "SolicitudDeNavesApoyo.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaTransporteFurtivo.h"
#include "NaveEnemigaTransporteLogistico.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveReabastecimientoEnergia.h"
#include "NaveReabastecimientoMunicion.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaNodrizaBlindada.h"
#include "NaveEnemigaNodrizaTactico.h"

ANaveEnemiga* ASolicitudDeNavesApoyo::CrearNaveEnemiga(FString NombreNave)
{
	//ANaveEnemiga* NaveEnemiga = nullptr;
	if (NombreNave == "NaveEnemigaTransporte")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaTransporte>(ANaveEnemigaTransporte::StaticClass());
	}
	else if (NombreNave == "NaveEnemigaTransporteFurtivo")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaTransporteFurtivo>(ANaveEnemigaTransporteFurtivo::StaticClass());
	}
	else if (NombreNave == "NaveEnemigaTransporteLogistico")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaTransporteLogistico>(ANaveEnemigaTransporteLogistico::StaticClass());
	}
	else if (NombreNave == "NaveEnemigaReabastecimiento")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaReabastecimiento>(ANaveEnemigaReabastecimiento::StaticClass());
	}
	else if (NombreNave == "NaveReabastecimientoEnergia")
	{
		return GetWorld()->SpawnActor<ANaveReabastecimientoEnergia>(ANaveReabastecimientoEnergia::StaticClass());
	}
	else if (NombreNave == "NaveReabastecimientoMunicion")
	{
		return GetWorld()->SpawnActor<ANaveReabastecimientoMunicion>(ANaveReabastecimientoMunicion::StaticClass());
	}
	else if (NombreNave == "NaveEnemigaNodriza")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaNodriza>(ANaveEnemigaNodriza::StaticClass());
	}
	else if (NombreNave == "NaveEnemigaNodrizaBlindada")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaNodrizaBlindada>(ANaveEnemigaNodrizaBlindada::StaticClass());
	}
	else if (NombreNave == "NaveEnemigaNodrizaTactico")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaNodrizaTactico>(ANaveEnemigaNodrizaTactico::StaticClass());
	}
	else return nullptr;
}

