# Start point
# Functions
import Functions as fn

fileData = fn.ReadDataOfFile("data.txt")

fn.CreateEmployeeDictionary(fileData)
fn.CreateCustomerDictionary(fileData)
fn.CreateTransactionDictionary(fileData)

fn.Transaction()
testData = fn.ReadDataOfFile("testData.txt")
fn.TestResult(testData)

fn.WriteTransactionLogToFile("transactionLog.txt")
