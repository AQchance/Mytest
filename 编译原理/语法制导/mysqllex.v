#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 37 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# mysql4lex.v
# Lex verbose file generated from mysql4lex.l.
# 
# Date: 06/26/20
# Time: 08:46:48
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ ]+

    2  [\n]+

    3  "CREATE"

    4  "DATABASE"

    5  "USE"

    6  "SHOW"

    7  "DATABASES"

    8  "DROP"

    9  "TABLE"

   10  "TABLES"

   11  "INT"

   12  "CHAR"

   13  "INSERT"

   14  "INTO"

   15  "VALUES"

   16  "SELECT"

   17  "FROM"

   18  "WHERE"

   19  "AND"

   20  "OR"

   21  "NOT"

   22  "TRUE"

   23  "FALSE"

   24  "DELETE"

   25  "UPDATE"

   26  "SET"

   27  "EXIT"

   28  "QUIT"

   29  "("

   30  ")"

   31  ","

   32  ";"

   33  "+"

   34  "-"

   35  "*"

   36  "/"

   37  ">"

   38  "<"

   39  "="

   40  "!"

   41  "\'"

   42  [0-9]+

   43  [a-zA-Z][a-zA-Z0-9_]*

   44  [a-zA-Z0-9_]*


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x0a               goto 3
	0x20               goto 4
	0x21               goto 5
	0x27               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b               goto 10
	0x2c               goto 11
	0x2d               goto 12
	0x2f               goto 13
	0x30 - 0x39 (10)   goto 14
	0x3b               goto 15
	0x3c               goto 16
	0x3d               goto 17
	0x3e               goto 18
	0x41               goto 19
	0x42               goto 20
	0x43               goto 21
	0x44               goto 22
	0x45               goto 23
	0x46               goto 24
	0x47 - 0x48 (2)    goto 20
	0x49               goto 25
	0x4a - 0x4d (4)    goto 20
	0x4e               goto 26
	0x4f               goto 27
	0x50               goto 20
	0x51               goto 28
	0x52               goto 20
	0x53               goto 29
	0x54               goto 30
	0x55               goto 31
	0x56               goto 32
	0x57               goto 33
	0x58 - 0x5a (3)    goto 20
	0x5f               goto 34
	0x61               goto 19
	0x62               goto 20
	0x63               goto 21
	0x64               goto 22
	0x65               goto 23
	0x66               goto 24
	0x67 - 0x68 (2)    goto 20
	0x69               goto 25
	0x6a - 0x6d (4)    goto 20
	0x6e               goto 26
	0x6f               goto 27
	0x70               goto 20
	0x71               goto 28
	0x72               goto 20
	0x73               goto 29
	0x74               goto 30
	0x75               goto 31
	0x76               goto 32
	0x77               goto 33
	0x78 - 0x7a (3)    goto 20


state 2
	^INITIAL

	0x0a               goto 3
	0x20               goto 4
	0x21               goto 5
	0x27               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b               goto 10
	0x2c               goto 11
	0x2d               goto 12
	0x2f               goto 13
	0x30 - 0x39 (10)   goto 14
	0x3b               goto 15
	0x3c               goto 16
	0x3d               goto 17
	0x3e               goto 18
	0x41               goto 19
	0x42               goto 20
	0x43               goto 21
	0x44               goto 22
	0x45               goto 23
	0x46               goto 24
	0x47 - 0x48 (2)    goto 20
	0x49               goto 25
	0x4a - 0x4d (4)    goto 20
	0x4e               goto 26
	0x4f               goto 27
	0x50               goto 20
	0x51               goto 28
	0x52               goto 20
	0x53               goto 29
	0x54               goto 30
	0x55               goto 31
	0x56               goto 32
	0x57               goto 33
	0x58 - 0x5a (3)    goto 20
	0x5f               goto 34
	0x61               goto 19
	0x62               goto 20
	0x63               goto 21
	0x64               goto 22
	0x65               goto 23
	0x66               goto 24
	0x67 - 0x68 (2)    goto 20
	0x69               goto 25
	0x6a - 0x6d (4)    goto 20
	0x6e               goto 26
	0x6f               goto 27
	0x70               goto 20
	0x71               goto 28
	0x72               goto 20
	0x73               goto 29
	0x74               goto 30
	0x75               goto 31
	0x76               goto 32
	0x77               goto 33
	0x78 - 0x7a (3)    goto 20


state 3
	0x0a               goto 3

	match 2


state 4
	0x20               goto 4

	match 1


state 5
	match 40


state 6
	match 41


state 7
	match 29


state 8
	match 30


state 9
	match 35


state 10
	match 33


state 11
	match 31


state 12
	match 34


state 13
	match 36


state 14
	0x30 - 0x39 (10)   goto 14
	0x41 - 0x5a (26)   goto 34
	0x5f               goto 34
	0x61 - 0x7a (26)   goto 34

	match 42


state 15
	match 32


state 16
	match 38


state 17
	match 39


state 18
	match 37


state 19
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4d (13)   goto 20
	0x4e               goto 35
	0x4f - 0x5a (12)   goto 20
	0x5f               goto 20
	0x61 - 0x6d (13)   goto 20
	0x6e               goto 35
	0x6f - 0x7a (12)   goto 20

	match 43


state 20
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 43


state 21
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x47 (7)    goto 20
	0x48               goto 36
	0x49 - 0x51 (9)    goto 20
	0x52               goto 37
	0x53 - 0x5a (8)    goto 20
	0x5f               goto 20
	0x61 - 0x67 (7)    goto 20
	0x68               goto 36
	0x69 - 0x71 (9)    goto 20
	0x72               goto 37
	0x73 - 0x7a (8)    goto 20

	match 43


state 22
	0x30 - 0x39 (10)   goto 20
	0x41               goto 38
	0x42 - 0x44 (3)    goto 20
	0x45               goto 39
	0x46 - 0x51 (12)   goto 20
	0x52               goto 40
	0x53 - 0x5a (8)    goto 20
	0x5f               goto 20
	0x61               goto 38
	0x62 - 0x64 (3)    goto 20
	0x65               goto 39
	0x66 - 0x71 (12)   goto 20
	0x72               goto 40
	0x73 - 0x7a (8)    goto 20

	match 43


state 23
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x57 (23)   goto 20
	0x58               goto 41
	0x59 - 0x5a (2)    goto 20
	0x5f               goto 20
	0x61 - 0x77 (23)   goto 20
	0x78               goto 41
	0x79 - 0x7a (2)    goto 20

	match 43


state 24
	0x30 - 0x39 (10)   goto 20
	0x41               goto 42
	0x42 - 0x51 (16)   goto 20
	0x52               goto 43
	0x53 - 0x5a (8)    goto 20
	0x5f               goto 20
	0x61               goto 42
	0x62 - 0x71 (16)   goto 20
	0x72               goto 43
	0x73 - 0x7a (8)    goto 20

	match 43


state 25
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4d (13)   goto 20
	0x4e               goto 44
	0x4f - 0x5a (12)   goto 20
	0x5f               goto 20
	0x61 - 0x6d (13)   goto 20
	0x6e               goto 44
	0x6f - 0x7a (12)   goto 20

	match 43


state 26
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4e (14)   goto 20
	0x4f               goto 45
	0x50 - 0x5a (11)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 45
	0x70 - 0x7a (11)   goto 20

	match 43


state 27
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x51 (17)   goto 20
	0x52               goto 46
	0x53 - 0x5a (8)    goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 46
	0x73 - 0x7a (8)    goto 20

	match 43


state 28
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x54 (20)   goto 20
	0x55               goto 47
	0x56 - 0x5a (5)    goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 47
	0x76 - 0x7a (5)    goto 20

	match 43


state 29
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 48
	0x46 - 0x47 (2)    goto 20
	0x48               goto 49
	0x49 - 0x5a (18)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 48
	0x66 - 0x67 (2)    goto 20
	0x68               goto 49
	0x69 - 0x7a (18)   goto 20

	match 43


state 30
	0x30 - 0x39 (10)   goto 20
	0x41               goto 50
	0x42 - 0x51 (16)   goto 20
	0x52               goto 51
	0x53 - 0x5a (8)    goto 20
	0x5f               goto 20
	0x61               goto 50
	0x62 - 0x71 (16)   goto 20
	0x72               goto 51
	0x73 - 0x7a (8)    goto 20

	match 43


state 31
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4f (15)   goto 20
	0x50               goto 52
	0x51 - 0x52 (2)    goto 20
	0x53               goto 53
	0x54 - 0x5a (7)    goto 20
	0x5f               goto 20
	0x61 - 0x6f (15)   goto 20
	0x70               goto 52
	0x71 - 0x72 (2)    goto 20
	0x73               goto 53
	0x74 - 0x7a (7)    goto 20

	match 43


state 32
	0x30 - 0x39 (10)   goto 20
	0x41               goto 54
	0x42 - 0x5a (25)   goto 20
	0x5f               goto 20
	0x61               goto 54
	0x62 - 0x7a (25)   goto 20

	match 43


state 33
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x47 (7)    goto 20
	0x48               goto 55
	0x49 - 0x5a (18)   goto 20
	0x5f               goto 20
	0x61 - 0x67 (7)    goto 20
	0x68               goto 55
	0x69 - 0x7a (18)   goto 20

	match 43


state 34
	0x30 - 0x39 (10)   goto 34
	0x41 - 0x5a (26)   goto 34
	0x5f               goto 34
	0x61 - 0x7a (26)   goto 34

	match 44


state 35
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x43 (3)    goto 20
	0x44               goto 56
	0x45 - 0x5a (22)   goto 20
	0x5f               goto 20
	0x61 - 0x63 (3)    goto 20
	0x64               goto 56
	0x65 - 0x7a (22)   goto 20

	match 43


state 36
	0x30 - 0x39 (10)   goto 20
	0x41               goto 57
	0x42 - 0x5a (25)   goto 20
	0x5f               goto 20
	0x61               goto 57
	0x62 - 0x7a (25)   goto 20

	match 43


state 37
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 58
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 58
	0x66 - 0x7a (21)   goto 20

	match 43


state 38
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 59
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 59
	0x75 - 0x7a (6)    goto 20

	match 43


state 39
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4b (11)   goto 20
	0x4c               goto 60
	0x4d - 0x5a (14)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 60
	0x6d - 0x7a (14)   goto 20

	match 43


state 40
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4e (14)   goto 20
	0x4f               goto 61
	0x50 - 0x5a (11)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 61
	0x70 - 0x7a (11)   goto 20

	match 43


state 41
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x48 (8)    goto 20
	0x49               goto 62
	0x4a - 0x5a (17)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 62
	0x6a - 0x7a (17)   goto 20

	match 43


state 42
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4b (11)   goto 20
	0x4c               goto 63
	0x4d - 0x5a (14)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 63
	0x6d - 0x7a (14)   goto 20

	match 43


state 43
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4e (14)   goto 20
	0x4f               goto 64
	0x50 - 0x5a (11)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 64
	0x70 - 0x7a (11)   goto 20

	match 43


state 44
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x52 (18)   goto 20
	0x53               goto 65
	0x54               goto 66
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x72 (18)   goto 20
	0x73               goto 65
	0x74               goto 66
	0x75 - 0x7a (6)    goto 20

	match 43


state 45
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 67
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 67
	0x75 - 0x7a (6)    goto 20

	match 43


state 46
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 20


state 47
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x48 (8)    goto 20
	0x49               goto 68
	0x4a - 0x5a (17)   goto 20
	0x5f               goto 20
	0x61 - 0x68 (8)    goto 20
	0x69               goto 68
	0x6a - 0x7a (17)   goto 20

	match 43


state 48
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4b (11)   goto 20
	0x4c               goto 69
	0x4d - 0x53 (7)    goto 20
	0x54               goto 70
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 69
	0x6d - 0x73 (7)    goto 20
	0x74               goto 70
	0x75 - 0x7a (6)    goto 20

	match 43


state 49
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4e (14)   goto 20
	0x4f               goto 71
	0x50 - 0x5a (11)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 71
	0x70 - 0x7a (11)   goto 20

	match 43


state 50
	0x30 - 0x39 (10)   goto 20
	0x41               goto 20
	0x42               goto 72
	0x43 - 0x5a (24)   goto 20
	0x5f               goto 20
	0x61               goto 20
	0x62               goto 72
	0x63 - 0x7a (24)   goto 20

	match 43


state 51
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x54 (20)   goto 20
	0x55               goto 73
	0x56 - 0x5a (5)    goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 73
	0x76 - 0x7a (5)    goto 20

	match 43


state 52
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x43 (3)    goto 20
	0x44               goto 74
	0x45 - 0x5a (22)   goto 20
	0x5f               goto 20
	0x61 - 0x63 (3)    goto 20
	0x64               goto 74
	0x65 - 0x7a (22)   goto 20

	match 43


state 53
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 75
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 75
	0x66 - 0x7a (21)   goto 20

	match 43


state 54
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4b (11)   goto 20
	0x4c               goto 76
	0x4d - 0x5a (14)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 76
	0x6d - 0x7a (14)   goto 20

	match 43


state 55
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 77
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 77
	0x66 - 0x7a (21)   goto 20

	match 43


state 56
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 19


state 57
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x51 (17)   goto 20
	0x52               goto 78
	0x53 - 0x5a (8)    goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 78
	0x73 - 0x7a (8)    goto 20

	match 43


state 58
	0x30 - 0x39 (10)   goto 20
	0x41               goto 79
	0x42 - 0x5a (25)   goto 20
	0x5f               goto 20
	0x61               goto 79
	0x62 - 0x7a (25)   goto 20

	match 43


state 59
	0x30 - 0x39 (10)   goto 20
	0x41               goto 80
	0x42 - 0x5a (25)   goto 20
	0x5f               goto 20
	0x61               goto 80
	0x62 - 0x7a (25)   goto 20

	match 43


state 60
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 81
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 81
	0x66 - 0x7a (21)   goto 20

	match 43


state 61
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4f (15)   goto 20
	0x50               goto 82
	0x51 - 0x5a (10)   goto 20
	0x5f               goto 20
	0x61 - 0x6f (15)   goto 20
	0x70               goto 82
	0x71 - 0x7a (10)   goto 20

	match 43


state 62
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 83
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 83
	0x75 - 0x7a (6)    goto 20

	match 43


state 63
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x52 (18)   goto 20
	0x53               goto 84
	0x54 - 0x5a (7)    goto 20
	0x5f               goto 20
	0x61 - 0x72 (18)   goto 20
	0x73               goto 84
	0x74 - 0x7a (7)    goto 20

	match 43


state 64
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4c (12)   goto 20
	0x4d               goto 85
	0x4e - 0x5a (13)   goto 20
	0x5f               goto 20
	0x61 - 0x6c (12)   goto 20
	0x6d               goto 85
	0x6e - 0x7a (13)   goto 20

	match 43


state 65
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 86
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 86
	0x66 - 0x7a (21)   goto 20

	match 43


state 66
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4e (14)   goto 20
	0x4f               goto 87
	0x50 - 0x5a (11)   goto 20
	0x5f               goto 20
	0x61 - 0x6e (14)   goto 20
	0x6f               goto 87
	0x70 - 0x7a (11)   goto 20

	match 11


state 67
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 21


state 68
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 88
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 88
	0x75 - 0x7a (6)    goto 20

	match 43


state 69
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 89
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 89
	0x66 - 0x7a (21)   goto 20

	match 43


state 70
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 26


state 71
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x56 (22)   goto 20
	0x57               goto 90
	0x58 - 0x5a (3)    goto 20
	0x5f               goto 20
	0x61 - 0x76 (22)   goto 20
	0x77               goto 90
	0x78 - 0x7a (3)    goto 20

	match 43


state 72
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x4b (11)   goto 20
	0x4c               goto 91
	0x4d - 0x5a (14)   goto 20
	0x5f               goto 20
	0x61 - 0x6b (11)   goto 20
	0x6c               goto 91
	0x6d - 0x7a (14)   goto 20

	match 43


state 73
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 92
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 92
	0x66 - 0x7a (21)   goto 20

	match 43


state 74
	0x30 - 0x39 (10)   goto 20
	0x41               goto 93
	0x42 - 0x5a (25)   goto 20
	0x5f               goto 20
	0x61               goto 93
	0x62 - 0x7a (25)   goto 20

	match 43


state 75
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 5


state 76
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x54 (20)   goto 20
	0x55               goto 94
	0x56 - 0x5a (5)    goto 20
	0x5f               goto 20
	0x61 - 0x74 (20)   goto 20
	0x75               goto 94
	0x76 - 0x7a (5)    goto 20

	match 43


state 77
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x51 (17)   goto 20
	0x52               goto 95
	0x53 - 0x5a (8)    goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 95
	0x73 - 0x7a (8)    goto 20

	match 43


state 78
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 12


state 79
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 96
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 96
	0x75 - 0x7a (6)    goto 20

	match 43


state 80
	0x30 - 0x39 (10)   goto 20
	0x41               goto 20
	0x42               goto 97
	0x43 - 0x5a (24)   goto 20
	0x5f               goto 20
	0x61               goto 20
	0x62               goto 97
	0x63 - 0x7a (24)   goto 20

	match 43


state 81
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 98
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 98
	0x75 - 0x7a (6)    goto 20

	match 43


state 82
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 8


state 83
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 27


state 84
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 99
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 99
	0x66 - 0x7a (21)   goto 20

	match 43


state 85
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 17


state 86
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x51 (17)   goto 20
	0x52               goto 100
	0x53 - 0x5a (8)    goto 20
	0x5f               goto 20
	0x61 - 0x71 (17)   goto 20
	0x72               goto 100
	0x73 - 0x7a (8)    goto 20

	match 43


state 87
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 14


state 88
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 28


state 89
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x42 (2)    goto 20
	0x43               goto 101
	0x44 - 0x5a (23)   goto 20
	0x5f               goto 20
	0x61 - 0x62 (2)    goto 20
	0x63               goto 101
	0x64 - 0x7a (23)   goto 20

	match 43


state 90
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 6


state 91
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 102
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 102
	0x66 - 0x7a (21)   goto 20

	match 43


state 92
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 22


state 93
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 103
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 103
	0x75 - 0x7a (6)    goto 20

	match 43


state 94
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 104
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 104
	0x66 - 0x7a (21)   goto 20

	match 43


state 95
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 105
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 105
	0x66 - 0x7a (21)   goto 20

	match 43


state 96
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 106
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 106
	0x66 - 0x7a (21)   goto 20

	match 43


state 97
	0x30 - 0x39 (10)   goto 20
	0x41               goto 107
	0x42 - 0x5a (25)   goto 20
	0x5f               goto 20
	0x61               goto 107
	0x62 - 0x7a (25)   goto 20

	match 43


state 98
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 108
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 108
	0x66 - 0x7a (21)   goto 20

	match 43


state 99
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 23


state 100
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 109
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 109
	0x75 - 0x7a (6)    goto 20

	match 43


state 101
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x53 (19)   goto 20
	0x54               goto 110
	0x55 - 0x5a (6)    goto 20
	0x5f               goto 20
	0x61 - 0x73 (19)   goto 20
	0x74               goto 110
	0x75 - 0x7a (6)    goto 20

	match 43


state 102
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x52 (18)   goto 20
	0x53               goto 111
	0x54 - 0x5a (7)    goto 20
	0x5f               goto 20
	0x61 - 0x72 (18)   goto 20
	0x73               goto 111
	0x74 - 0x7a (7)    goto 20

	match 9


state 103
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 112
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 112
	0x66 - 0x7a (21)   goto 20

	match 43


state 104
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x52 (18)   goto 20
	0x53               goto 113
	0x54 - 0x5a (7)    goto 20
	0x5f               goto 20
	0x61 - 0x72 (18)   goto 20
	0x73               goto 113
	0x74 - 0x7a (7)    goto 20

	match 43


state 105
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 18


state 106
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 3


state 107
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x52 (18)   goto 20
	0x53               goto 114
	0x54 - 0x5a (7)    goto 20
	0x5f               goto 20
	0x61 - 0x72 (18)   goto 20
	0x73               goto 114
	0x74 - 0x7a (7)    goto 20

	match 43


state 108
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 24


state 109
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 13


state 110
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 16


state 111
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 10


state 112
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 25


state 113
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 15


state 114
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x44 (4)    goto 20
	0x45               goto 115
	0x46 - 0x5a (21)   goto 20
	0x5f               goto 20
	0x61 - 0x64 (4)    goto 20
	0x65               goto 115
	0x66 - 0x7a (21)   goto 20

	match 43


state 115
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x52 (18)   goto 20
	0x53               goto 116
	0x54 - 0x5a (7)    goto 20
	0x5f               goto 20
	0x61 - 0x72 (18)   goto 20
	0x73               goto 116
	0x74 - 0x7a (7)    goto 20

	match 4


state 116
	0x30 - 0x39 (10)   goto 20
	0x41 - 0x5a (26)   goto 20
	0x5f               goto 20
	0x61 - 0x7a (26)   goto 20

	match 7


#############################################################################
# Summary
#############################################################################

1 start state(s)
44 expression(s), 116 state(s)


#############################################################################
# End of File
#############################################################################
