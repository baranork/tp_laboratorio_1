
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

typedef struct
{
    int sector;
    char nombreSector[20];
} eSector;

int initEmployees(eEmployee[], int);
void addEmployee(eEmployee[], eSector[], int, int);
void menuMostrar(eEmployee[], eSector[], int, int);
void menuMostrarOrden(eEmployee[], eSector[], int, int);
void sortEmployees(eEmployee[], eSector[], int, int);
void printEmployees(eEmployee[], eSector[], int);
int removeEmployee(eEmployee[], eSector[], int, int);
void modificarEmpleado(eEmployee[], eSector[], int, int);
void sumarPromediarSueldos(eEmployee[], int);
int findEmployeeById(eEmployee[], int, int);
void hardcodearDatosEmpleados(eEmployee[], int);
void mostrarSector(eSector[], int);
void mayorAlPromedio(eEmployee[], int);

int menuDeOpciones(char[]);
int buscarLibre(eEmployee[], int);
