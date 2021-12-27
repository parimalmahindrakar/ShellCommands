library("Metrics")
library("DAAG")
data1=read.csv("DatasetRegression_Advertising.csv")
View(data1)
data=data1[-1]
dim(data)
head(data)

train=data[1:140,]
head(train)
test=data[141:200,]
head(test)

col = cbind("TV","Radio","Newspaper")
col

TV_train = lm(Sales~TV,data=train)
Radio_train = lm(Sales~Radio,data=train)
Newspaper_train = lm(Sales~Newspaper,data=train)

plot(train$Sales~train$TV,xlab = "TV",ylab = "Sales")
abline(TV_train)

plot(train$Sales~train$Radio,xlab = "Radio",ylab = "Sales")
abline(Radio_train)

plot(train$Sales~train$Newspaper,xlab = "Newspaper",ylab = "Sales")
abline(Newspaper_train)

TV_pre = predict(TV_train,train)
Radio_pre = predict(Radio_train,train)
Newspaper_pre = predict(Newspaper_train,train)

TV_test = predict(TV_train,test)
Radio_test = predict(Radio_train,test)
Newspaper_test = predict(Newspaper_train,test)

TVtrain_MSE = mse(train$Sales,TV_pre)
Radiotrain_MSE = mse(train$Sales,Radio_pre)
Newspapertrain_MSE = mse(train$Sales,Newspaper_pre)
TrainMSE = c(TVtrain_MSE,Radiotrain_MSE,Newspapertrain_MSE)
TrainMSE

TVtest_MSE = mse(test$Sales,TV_test)
Radiotest_MSE = mse(test$Sales,Radio_test)
Newspapertest_MSE = mse(test$Sales,Newspaper_test)
TestMSE = c(TVtest_MSE,Radiotest_MSE,Newspapertest_MSE)
TestMSE

barplot(TrainMSE,width=0.02,xlab = "data",ylab = "Error",main = "Training error")
barplot(TestMSE,width=0.02,xlab = "data",ylab = "Error",main = "Testing error")

modelTV = cv.lm(data,(Sales~TV),m=5)
modelRadio = cv.lm(data,(Sales~Radio),m=5)
modelNewspaper = cv.lm(data,(Sales~Newspaper),m=5)

