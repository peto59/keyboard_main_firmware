MATRIX_ROWS = 10
MATRIX_COLS = 19

# print("[")
# for r in range(MATRIX_ROWS):
#     for c in range(MATRIX_COLS):
#         print("                {\"matrix\": ["+str(r)+", "+str(c)+"], \"x\": "+str(c)+", \"y\": "+str(r)+", \"h\": 1, \"w\": 1, \"label\": \"none\"},")
# print("]")


for r in range(MATRIX_ROWS):
    for c in range(MATRIX_COLS):
        print("K"+str(r)+str(c),end=", ")
    print("\\\n",end="")
