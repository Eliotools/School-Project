! EPITECH PROJECT, 2021
! B-MAT-400-LIL-4-1-202unsold-thomas.gillet [WSL: Ubuntu]
! File description:
! PROJ


PROGRAM main      
IMPLICIT NONE

   CALL check_arg()
   CALL run()

CONTAINS

    SUBROUTINE check_arg()
    IMPLICIT NONE
        INTEGER :: i, tmp
        CHARACTER(len=32) :: arg
        IF (command_argument_count() > 3) CALL my_exit("ERROR -> INVALIDE NUMBER OF ARG")
        IF (command_argument_count() < 2) THEN
            IF (arg == "-h") CALL usage()
            CALL my_exit("ERROR -> INVALIDE NUMBER OF ARG")
        END IF
        
        DO i = 1, iargc()
            CALL getarg(i, arg)
            READ (arg,'(i3)') tmp
            IF (tmp < 50) CALL my_exit("ERROR ->ARG SHOULD BE >= 50")
        END DO
    END SUBROUTINE check_arg

    SUBROUTINE usage()
    IMPLICIT NONE
    PRINT '(A)', "USAGE"
    PRINT '(A,A)', char(9), "./202unsold a b"
    PRINT '(A)', "DESCRIPTION"
    PRINT '(A,A,A,A)', char(9), "a", char(9), "constant computed from past results"
    PRINT '(A,A,A,A)', char(9), "b", char(9), "constant computed from past results"
    CALL EXIT()
    END SUBROUTINE usage

    SUBROUTINE my_exit (str)
    IMPLICIT NONE

        CHARACTER(len=*), INTENT(IN) :: str
        
        PRINT *,str
        CALL EXIT(84)
    END SUBROUTINE my_exit

    SUBROUTINE run()
    IMPLICIT NONE
        
        INTEGER, DIMENSION (2) :: arg
        REAL, DIMENSION (5,5) :: array
        REAL, DIMENSION (10) :: list
        REAL, DIMENSION (5,2) :: lay
    CALL fill_array(arg)
    array = get_array(arg(1), arg(2))
    lay = first_phase(array)
    list = second_phase(array)
    CALL third_phase(arg, array, list, lay)
    END SUBROUTINE run

    SUBROUTINE fill_array (a)
    IMPLICIT NONE

        CHARACTER(len=32) :: arg
        INTEGER, DIMENSION (2), INTENT (OUT) :: a
        INTEGER :: i

        DO i = 1, iargc()
            CALL getarg(i, arg)
            read (arg,'(i3)') a(i)
        END DO
    END SUBROUTINE fill_array

    FUNCTION get_array(a, b) result(array)
    IMPLICIT NONE

        INTEGER, INTENT(IN) :: a, b
        INTEGER :: x, y
        REAL, DIMENSION (5,5) :: array
        DO x = 1, 5
            DO y = 1, 5
                array(x,y) = my_calc(a, b, x*10, y*10)
            END DO
        END DO
    END FUNCTION get_array

    FUNCTION my_calc(a, b, x, y) result(final)
    IMPLICIT NONE
        INTEGER, INTENT(IN) :: a, b, x, y
        REAL             :: final, check

        final = ((5*a-150)*(5*b-150))
        CALL check_if_null(final)
        final = ((a-x)*(b-y))/final
        RETURN
    END FUNCTION

    SUBROUTINE check_if_null(nb)
    IMPLICIT NONE

        REAL, INTENT(IN) :: nb

        IF (nb == 0) THEN
            CALl my_exit("DIVISION BY ZERO :(")
        END IF
    END SUBROUTINE check_if_null

    FUNCTION first_phase(array) result (lay)
    IMPLICIT NONE
        REAL, DIMENSION (5,5), INTENT(IN) :: array
        REAL, DIMENSION (5,2) :: lay
        INTEGER :: x, y, tmp

        tmp = 10
        PRINT '(A)',"--------------------------------------------------------------------------------"
        PRINT "(A,$)", char(9)
        DO x = 1, 5
            PRINT "(A,I2,A,$)", "X=",x*10,char(9)
        END DO
        PRINT "(A)", "Y law"
        DO x = 1, 5
            PRINT "(A,I2,A,$)", "Y=",(tmp),char(9)
            DO y = 1, 5
                PRINT "(F5.3,A,$)", array(y,x),char(9)
            END DO
            lay(x,2) = get_y_lay(x, array)
            PRINT "(F5.3)", lay(x,2)
            tmp = tmp + 10
        END DO
        PRINT "(A,A,$)", "X law", char(9)
        DO x = 1, 5
            lay(x,1) = get_x_lay(x, array)
            PRINT "(F5.3,A,$)",lay(x,1), char(9)
        END DO
        PRINT "(A)","1.000"
        PRINT '(A)',"--------------------------------------------------------------------------------"
    END FUNCTION first_phase

    FUNCTION get_y_lay(y, array) result (tmp)
    IMPLICIT NONE
        REAL, DIMENSION (5,5), INTENT(IN) :: array
        INTEGER, INTENT(IN) :: y
        INTEGER :: i
        REAL :: tmp

        tmp = 0
        DO i = 1, 5
            tmp = tmp + array(i,y)
        END DO
    END FUNCTION get_y_lay

    FUNCTION get_x_lay(x, array) result (tmp)
    IMPLICIT NONE
        REAL, DIMENSION (5,5), INTENT(IN) :: array
        INTEGER, INTENT(IN) :: x
        INTEGER :: i
        REAL :: tmp

        tmp = 0
        DO i = 1, 5
            tmp = tmp + array(x,i)
        END DO
    END FUNCTION get_x_lay

    SUBROUTINE print_lay(lay)
    IMPLICIT NONE
        REAL, DIMENSION (5,2), INTENT(OUT) :: lay
        INTEGER :: x, y
    DO x = 1, 2
        DO y = 1, 5
            PRINT "(F7.3,A,$)", lay(y,x)
        END DO
    END DO

    END SUBROUTINE print_lay

    FUNCTION second_phase(array) result(final)
    IMPLICIT NONE
        REAL, DIMENSION (5,5), INTENT(IN) :: array
        REAL, DIMENSION (10) :: final
        INTEGER :: x, y, z
        PRINT '(A,A,$)', "z",char(9)
        DO z = 2, 10
            PRINT "(I3,A,$)", z*10,char(9)
        END DO
        PRINT '(/,A,A,$)', "p(Z=z)", char(9)
        DO x = 1, 5
            DO y = 1, 5
            final(x + y) = final(x + y) + array(x, y)
            END DO
        END DO
        DO x = 2,10
            PRINT "(F5.3,A,$)", final(x),char(9)
        END DO
        PRINT *,""
        PRINT '(A)', "--------------------------------------------------------------------------------"
    END FUNCTION second_phase

    SUBROUTINE third_phase(arg, array, list, lay)
    IMPLICIT NONE
        INTEGER, DIMENSION (2), INTENT(IN) :: arg
        REAL, DIMENSION (5,5), INTENT(IN) :: array
        REAL, DIMENSION (10), INTENT(IN) :: list
        REAL, DIMENSION (5,2), INTENT(IN) :: lay
        REAL, DIMENSION (6) :: final
        INTEGER :: x

        DO x = 10, 50, 10
            final(1) =final(1) + x * lay(x/10,1)
            final(3) =final(3) + x * lay(x/10,2)
        END DO
        DO x = 10, 50, 10
            final(2) = final(2) + (x - final(1)) * (x - final(1))* lay(x/10,1)
            final(4) = final(4) + (x - final(3)) * (x - final(3))* lay(x/10,2)
        END DO
        DO x = 10, 100, 10
            final(5) = final(5) + x * list(x/10)
        END DO
        DO x = 10, 100, 10
            final(6) = final(6) + (x - final(5)) * (x - final(5))* list(x/10)
        END DO

        PRINT "(A,A,F4.1)", "expected value of X:", char(9), final(1)
        PRINT "(A,A,A,F5.1)", "variance of X:", char(9),char(9), final(2)
        PRINT "(A,A,F4.1)", "expected value of Y:", char(9), final(3)
        PRINT "(A,A,A,F5.1)", "variance of Y:", char(9),char(9), final(4)
        PRINT "(A,A,F4.1)", "expected value of Z:", char(9), final(5)
        PRINT "(A,A,A,F5.1)", "variance of Z:", char(9),char(9), final(6)
        PRINT '(A)', "--------------------------------------------------------------------------------"

    END SUBROUTINE third_phase

END PROGRAM main
