#!/usr/bin/env python
# coding: utf-8

# In[12]:


import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder
import matplotlib.pyplot as plt
import seaborn as sns
import os


# In[2]:


df= pd.read_csv('C:/Users/KLH/Desktop/gre-pred-master/gre.csv', encoding= 'latin')


# In[3]:


df.columns


# In[4]:


df= df.drop(['Student Name', 'Serial No.'], axis=1)


# In[5]:


df.head()


# In[6]:


label_encoder= LabelEncoder()


# In[7]:


df['Admitted']= label_encoder.fit_transform(df['Admitted'])


# In[8]:


print(df['Admitted'].unique())
df.head()


# In[9]:


df.describe()


# In[10]:


cor= df.corr()['Admitted']
print(cor)


# In[13]:


plt.figure(figsize=(15,8))
sns.heatmap(df.corr(), annot=True)


# In[25]:


X = df.iloc[:, 0:6].values
y = df.iloc[:, 7].values


# In[26]:


from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=0)


# In[27]:


# Feature Scaling
from sklearn.preprocessing import StandardScaler

sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)


# In[28]:


from sklearn.ensemble import RandomForestRegressor

regressor = RandomForestRegressor(n_estimators=20, random_state=0)
regressor.fit(X_train, y_train)
y_pred = regressor.predict(X_test)


# In[29]:


from sklearn import metrics

print('Mean Absolute Error:', metrics.mean_absolute_error(y_test, y_pred))
print('Mean Squared Error:', metrics.mean_squared_error(y_test, y_pred))
print('Root Mean Squared Error:', np.sqrt(metrics.mean_squared_error(y_test, y_pred)))


# In[ ]:




