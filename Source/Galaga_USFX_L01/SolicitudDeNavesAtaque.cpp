// Fill out your copyright notice in the Description page of Project Settings.


#include "SolicitudDeNavesAtaque.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaCazaSigilosa.h"
#include "NaveEnemigaCazaVeloz.h"

ANaveEnemiga* ASolicitudDeNavesAtaque::CrearNaveEnemiga(FString NombreNave, FVector Posicion, FRotator Rotacion)
{
	//ANaveEnemiga* NaveEnemiga = nullptr;
	if (NombreNave == "NaveEnemigaCaza")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaCaza>(ANaveEnemigaCaza::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaCazaSigilosa")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaCazaSigilosa>(ANaveEnemigaCazaSigilosa::StaticClass(), Posicion, Rotacion);
	}
	else if (NombreNave == "NaveEnemigaCazaVeloz")
	{
		return GetWorld()->SpawnActor<ANaveEnemigaCazaVeloz>(ANaveEnemigaCazaVeloz::StaticClass(), Posicion, Rotacion);
	}
	else return nullptr;
}

