# MonitorSystemQt

## 系统设计

**监视系统分为可视化和故障诊断两个界面**

```
1. 可视化界面并不主动发送任何数据，被动等到数据到来并进行显示，数据类型为`base.h`中`telemetryStruct`
2. 故障诊断界面需要主动发起数据请求，请求类型包括：
	2.1 故障参数等，数据类型为`base.h`中`faultParaStruct`
	2.2 保存对应数据等，数据类型为`base.h`中`saveDataStruct`
3. 故障诊断界面中也会被动等待数据并进行显示，数据类型为`base.h`中`faultResultStruct`
```

```
所有的传输数据均需符合base.h中定义和格式和类型
```
