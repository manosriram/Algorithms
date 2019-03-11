import datetime

finalDict = {}
name = ""
book = ""
finalArray = []
g = []
cur = ""
category = ""
booksDiction = {}
borrowersDiction = {}
checkoutsDiction = {}
dateDiction = {}
category = ""
flag = 0
category = str(input())
index = 0
if category == "Books":
    while flag == 0:
        cur = str(input())
        if cur == "Borrowers":
            while flag == 0:
                cur = str(input())
                if cur == "Checkouts":
                    while flag == 0:
                        cur = str(input())
                        if cur == "EndOfInput":
                            flag = 1
                        else:
                            g = cur.split("~")
                            name = borrowersDiction[g[0]]
                            book = booksDiction[g[1]]
                            bookCode = g[1]
                            date = g[2]

                            finalDict[date] = (
                                date + "~" + name + "~" + bookCode + "~" + book
                            )
                            index += 1

                            finalArray.append(finalDict[date])

                else:
                    g = cur.split("~")
                    borrowersDiction[g[0]] = g[1]

        else:
            g = cur.split("~")
            booksDiction[g[0]] = g[1]

for t in finalArray:
    print(t)
