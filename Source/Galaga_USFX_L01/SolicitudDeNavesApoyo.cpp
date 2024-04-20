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

ANaveEnemiga* ASolicitudDeNavesApoyo::CrearNaveEnemiga(FString NombreNave, FVector Posicion, FRotator Rotacion)
{
	//ANaveEnemiga* NaveEnemiga = nullptr;
	if (NombreNave == "NaveEnemigaTransporte")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaTransporte>(ANaveEnemigaTransporte::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaTransporteFurtivo")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaTransporteFurtivo>(ANaveEnemigaTransporteFurtivo::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaTransporteLogistico")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaTransporteLogistico>(ANaveEnemigaTransporteLogistico::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaReabastecimiento")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaReabastecimiento>(ANaveEnemigaReabastecimiento::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveReabastecimientoEnergia")
	{
		return GetWorld()->SpawnActor<ANaveReabastecimientoEnergia>(ANaveReabastecimientoEnergia::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveReabastecimientoMunicion")
	{
		return GetWorld()->SpawnActor<ANaveReabastecimientoMunicion>(ANaveReabastecimientoMunicion::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaNodriza")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaNodriza>(ANaveEnemigaNodriza::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaNodrizaBlindada")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaNodrizaBlindada>(ANaveEnemigaNodrizaBlindada::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaNodrizaTactico")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaNodrizaTactico>(ANaveEnemigaNodrizaTactico::StaticClass(), Posicion, Rotacion);
	}
	else return nullptr;
}

