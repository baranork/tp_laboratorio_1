#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"


Employee* employee_new()
{
    Employee* employee;
    employee=(Employee*)malloc(sizeof(Employee));
    if(employee==NULL)
    {
        printf("\nNo hay espacio suficiente.\n");
        system("pause");
    }
    return employee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int id;
    int horasTrabajadas;
    int sueldo;

    Employee* unEmpleado=employee_new();

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = atoi(sueldoStr);
    int ra, rb, rc, rd;

    if(unEmpleado != NULL)
    {
        ra = employee_setId(unEmpleado, id);
        rb = employee_setNombre(unEmpleado, nombreStr);
        rc = employee_setHorasTrabajadas(unEmpleado, horasTrabajadas);
        rd = employee_setSueldo(unEmpleado, sueldo);
    }
    if(ra==1 || rb==1 || rc==1 || rd==1)
    {
        printf("Hubo un error con la carga de datos. Por favor, intentelo de nuevo");
    }

    return unEmpleado;
}






int employee_setId(Employee* this,int id)
{
    int r = 1;

    if(id>0 && this!=NULL)
    {
        this->id = id;
        r = 0;
    }

    return r;
}
int employee_getId(Employee* this,int* id)
{
    int r = 1;

    if(this != NULL)
    {
        *id = this->id;
        r = 0;
    }
    return r;
}







int employee_setNombre(Employee* this,char* nombre)
{
    int r = 1;

    if(this!=NULL)
    {
        strcpy(this->nombre, nombre);
        r = 0;
    }

    return r;
}


int employee_getNombre(Employee* this, char* nombre)
{
    int r = 1;

    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        r = 0;
    }

    return r;
}







int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r = 1;

    if(horasTrabajadas>0 && this!=NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        r = 0;
    }

    return r;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int r = 1;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        r = 0;
    }
    return r;
}









int employee_setSueldo(Employee* this,int sueldo)
{
    int r = 1;

    if(sueldo>0 && this!=NULL)
    {
        this->sueldo = sueldo;
        r = 0;
    }

    return r;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int r = 1;

    if(this != NULL)
    {
        *sueldo = this->sueldo;
        r = 0;
    }
    return r;
}


int employee_CompareByNombre(void* e1,void* e2)
{
    int r=-1;
    Employee* empleado1;
    Employee* empleado2;

    if(e1!=NULL && e2!=NULL)
    {
        empleado1=(Employee*)e1;
        empleado2=(Employee*)e2;
        r=strcmp(empleado1->nombre,empleado2->nombre);
    }
    return r;

}

int employee_CompareByID(void* e1,void* e2)
{
    int r=-1;
    Employee* empleado1;
    Employee* empleado2;

    if(e1!=NULL && e2!=NULL)
    {
        empleado1=(Employee*)e1;
        empleado2=(Employee*)e2;
        if(empleado1->id > empleado2->id){
            r = 1;
        }
        else if(empleado1->id == empleado2->id){
            r = 0;
        }
    }
    return r;

}

int employee_CompareBySueldo(void* e1,void* e2)
{
    int r=-1;
    Employee* empleado1;
    Employee* empleado2;

    if(e1!=NULL && e2!=NULL)
    {
        empleado1=(Employee*)e1;
        empleado2=(Employee*)e2;
        if(empleado1->sueldo > empleado2->sueldo){
            r = 1;
        }
        else if(empleado1->sueldo == empleado2->sueldo){
            r = 0;
        }
    }
    return r;

}

int employee_CompareByHoras(void* e1,void* e2)
{
    int r=-1;
    Employee* empleado1;
    Employee* empleado2;

    if(e1!=NULL && e2!=NULL)
    {
        empleado1=(Employee*)e1;
        empleado2=(Employee*)e2;
        if(empleado1->horasTrabajadas > empleado2->horasTrabajadas){
            r = 1;
        }
        else if(empleado1->horasTrabajadas == empleado2->horasTrabajadas){
            r = 0;
        }
    }
    return r;

}
