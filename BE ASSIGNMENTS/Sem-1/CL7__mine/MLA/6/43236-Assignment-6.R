library(datasets)
data("iris")
str(iris)

summary(iris)

library(caret)
set.seed(100)
ind <- createDataPartition(iris$Species,p=0.80,list = F)
train <- iris[ind,]
test <- iris[-ind,]

dim(train)

dim(test)

library(psych)
pairs.panels(train[,-5],gap=0,bg=c("red","blue","yellow")[train$Species],pch=21)

pc <- prcomp(train[,-5],center = T,scale. = T)
pc

summary(pc)

pairs.panels(pc$x,gap=0,bg=c("red","blue","yellow")[train$Species],pch = 21)

library(devtools)
install_github("vqv/ggbiplot")
library(ggbiplot)
ggbiplot(pc, obs.scale = 1, var.scale = 1,groups = train$Species, ellipse = TRUE, circle = TRUE,ellipse.prob = 0.68) + scale_color_discrete(name = '') +  theme(legend.direction = 'horizontal', legend.position = 'top')

pred <- predict(pc,train)
train_1 <- data.frame(pred,train[5])
pred1 <- predict(pc,test)
test_1 <- data.frame(pred1,test[5])

library(nnet)
set.seed(100)
mymodel <- multinom(Species~PC1 +PC2,data = train_1)

summary(mymodel)

library(caret)
prd <- predict(mymodel,train_1)
confusionMatrix(prd,train_1$Species)

prt <- predict(mymodel,test_1)
confusionMatrix(prt,test_1$Species)

