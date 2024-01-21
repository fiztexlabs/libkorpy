# Вызов python-кода из РК КОРСАР

!!!1 Данный функционал доступен для KORSAR-MT начиная с версии 1.1.0.0.

Библиотека **libkorpy** содержит единственную экспортируемую функцию ```callFunc(const char *, double *, double *const)```, и является прослойкой между КОРСАРом и Python. 

## Пример использования бибилиотеки

В данном примере КОРСАР производит вызов пользовательского кода, описанного в файле [calc.py](/tests/calc.py). Python-скрипт **обязательно** должен содержать функцию ```korsar_mt```, принимающую и возвращающую массив значений.

### Рабочая директория

![](/doc/dir.png)

### kordat

```Fortran
!!bb Ключи основной процедуры

restart = 0;            
title = 'vb.036.003 CALL USER FUNCTION';
dt_max = 0.001;         
dt_out = 0.;           
fin_tim = 1.;           
dt_sav = 3;             
append_res = 1;         
append_sav = 1;         
! noption = '2,3,7,10';
check_only = 13;         
local_err = 1.0e-4;     
ngas = 'H2O, N2, O2';   
dt_diag = dt_out;       
inf = 1;                
accel_stat = 0;         
! nwsp_dat = 'd:\Users\BARINOV\KORSAR_Projects\nwsp_dat';

!!eb

MAIN:
! Возвращаемый код функции ALIEN
_errorCode = 0.;

! Массив аргументов и возвращаемых значений пользовательской функции
_IO(1:6) = 
2.,	! Количество аргументов
2., ! Количество выходных значений
1.,	! Значение первого аргумента
2.,	! Значение второго аргумента
0.,	! Первое возвращаемое значение
0.;	! Второе возвращаемое значение

! Вызов пользовательского кода из файла calc.py
_errorCode = ALIEN(0, 'libkorpy.dll', 'calc', 6, $_IO);

PRINT 'First output';
PRINT _IO(5);
PRINT 'Second output'
PRINT _IO(6);

LAYOUT

END

END
```

### calc.py

```Python
import numpy as np

def korsar_mt(a):
    print(a[0],a[1])
    return np.array([a[0] + a[1], 1])
```





