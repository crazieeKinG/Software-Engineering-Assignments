# Variables
employeeDetail = dict()
customerDetail = dict()
transactionDetail = list()
transactionLog = list()

# Functions
def ReadDataOfFile(filename: str):
    return open(filename, "r").readlines()


def CreateEmployeeDictionary(fileData: list):
    for line in fileData:
        line = line.strip().split()
        if line[0] == "e":
            id = line[1]
            employeeDetail[id] = line[2]


def CreateCustomerDictionary(fileData: list):
    for line in fileData:
        line = line.strip().split()
        if line[0] == "c":
            id = line[1]
            customerDetail[id] = dict()
            customerDetail[id]["name"] = line[2]
            customerDetail[id]["balance"] = float(line[3])


def CreateTransactionDictionary(fileData: list):
    for line in fileData:
        line = line.strip().split()
        if line[0] == "t":
            transactionData = dict()
            transactionData["customerId"] = line[1]
            transactionData["employeeId"] = line[2]
            transactionData["type"] = line[3]
            transactionData["amount"] = float(line[4])
            transactionDetail.append(transactionData)


def Deposit(transaction: dict):
    customerName = customerDetail[transaction["customerId"]]["name"]
    employeeName = employeeDetail[transaction["employeeId"]]
    customerDetail[transaction["customerId"]]["balance"] += transaction["amount"]
    transactionLog.append(f"{customerName} {employeeName} +${transaction['amount']:.2f} $ {customerDetail[transaction['customerId']]['balance']:.2f}\n")


def Withdraw(transaction: dict):
    customerName = customerDetail[transaction["customerId"]]["name"]
    employeeName = employeeDetail[transaction["employeeId"]]
    customerDetail[transaction["customerId"]]["balance"] -= transaction["amount"]
    transactionLog.append(f"{customerName} {employeeName} -${transaction['amount']:.2f} $ {customerDetail[transaction['customerId']]['balance']:.2f}\n")


def Transaction():
    transactionLog.append("123456789012345678901234567890123456789012345678901234567890\n")
    for transaction in transactionDetail:
        if transaction["type"] == "d":
            Deposit(transaction)
        else:
            Withdraw(transaction)


def WriteTransactionLogToFile(filename: str):
    with open(filename, "w") as fhandler:
        fhandler.writelines(transactionLog)
        print("Transaction log created !!!")

def TestResult(testData: list):
    for i in range(len(transactionLog)):
        if testData[i].strip() == transactionLog[i].strip():
            print(f"Correct output for {i + 1}th data.")
        else:
            print(f"Incorrect output for {i + 1}th data.")