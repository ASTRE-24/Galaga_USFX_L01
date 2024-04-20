// Fill out your copyright notice in the Description page of Project Settings.


#include "SolicitudDeNavesInformante.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaEspiaInfiltrada.h"
#include "NaveEnemigaEspiaTactica.h"

ANaveEnemiga* ASolicitudDeNavesInformante::CrearNaveEnemiga(FString NombreNave, FVector Posicion, FRotator Rotacion)
{
	//ANaveEnemiga* NaveEnemiga = nullptr;
	if (NombreNave == "NaveEnemigaEspia")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaEspia>(ANaveEnemigaEspia::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaEspiaInfiltrada")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaEspiaInfiltrada>(ANaveEnemigaEspiaInfiltrada::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaEspiaTactica")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaEspiaTactica>(ANaveEnemigaEspiaTactica::StaticClass(), Posicion, Rotacion);
	}
	else return nullptr;
}

