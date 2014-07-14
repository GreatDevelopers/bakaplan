-- MySQL dump 10.13  Distrib 5.5.35, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: bp_Next
-- ------------------------------------------------------
-- Server version	5.5.35-0+wheezy1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ClassDetail`
--

DROP TABLE IF EXISTS `ClassDetail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ClassDetail` (
  `ClassID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `ClassName` varchar(100) NOT NULL,
  `SubjectName` varchar(200) NOT NULL,
  `SubjectCode` varchar(200) NOT NULL,
  PRIMARY KEY (`ClassID`),
  KEY `FK_ProjectID` (`ProjectID`),
  CONSTRAINT `FK_ProjectID` FOREIGN KEY (`ProjectID`) REFERENCES `ProjectDetail` (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Class or Branch details including subjects and its code';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ContactDetail`
--

DROP TABLE IF EXISTS `ContactDetail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ContactDetail` (
  `ContactID` int(50) NOT NULL AUTO_INCREMENT,
  `Name` varchar(70) NOT NULL,
  `EmailID` varchar(100) NOT NULL,
  `Feedback` varchar(1500) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ContactID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Contact Form Detail or feedback form';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `DateSheet`
--

DROP TABLE IF EXISTS `DateSheet`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `DateSheet` (
  `DateSheetID` int(50) NOT NULL AUTO_INCREMENT,
  `ProjectID` int(50) NOT NULL,
  `Date` date NOT NULL,
  `SubjectCode` varchar(200) NOT NULL,
  PRIMARY KEY (`DateSheetID`),
  KEY `FK_D_ProjectID` (`ProjectID`),
  CONSTRAINT `FK_D_ProjectID` FOREIGN KEY (`ProjectID`) REFERENCES `ProjectDetail` (`ProjectID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ExamDetail`
--

DROP TABLE IF EXISTS `ExamDetail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ExamDetail` (
  `ExamID` int(50) NOT NULL AUTO_INCREMENT,
  `DateSheetID` int(50) NOT NULL,
  `ExamName` varchar(100) NOT NULL,
  `ExamSession` varchar(50) NOT NULL,
  `ExamTime` varchar(100) NOT NULL,
  `ExamVenue` varchar(100) NOT NULL,
  PRIMARY KEY (`ExamID`),
  KEY `FK_DateSheetID` (`DateSheetID`),
  CONSTRAINT `FK_DateSheetID` FOREIGN KEY (`DateSheetID`) REFERENCES `DateSheet` (`DateSheetID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ProjectDetail`
--

DROP TABLE IF EXISTS `ProjectDetail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ProjectDetail` (
  `ProjectID` int(50) NOT NULL AUTO_INCREMENT,
  `UserID` int(50) NOT NULL,
  `ProjectName` varchar(100) NOT NULL COMMENT 'Name of project',
  PRIMARY KEY (`ProjectID`),
  KEY `FK_UserID` (`UserID`),
  CONSTRAINT `FK_ProjectDetail` FOREIGN KEY (`UserID`) REFERENCES `User` (`UserID`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Project Detail given by user';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `Registration`
--

DROP TABLE IF EXISTS `Registration`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Registration` (
  `RegID` int(50) NOT NULL AUTO_INCREMENT,
  `EmailID` varchar(50) NOT NULL,
  `RegKey` varchar(100) NOT NULL,
  `Active` varchar(10) NOT NULL DEFAULT 'NO',
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`EmailID`),
  UNIQUE KEY `RegID` (`RegID`,`EmailID`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=latin1 COMMENT='Registration table for BaKaPlan';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ResetPassword`
--

DROP TABLE IF EXISTS `ResetPassword`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ResetPassword` (
  `ResetID` int(50) NOT NULL AUTO_INCREMENT,
  `UserID` int(70) NOT NULL,
  `ResetKey` varchar(100) NOT NULL,
  `Active` varchar(10) NOT NULL DEFAULT 'No',
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ResetID`),
  KEY `FK_R_UserID` (`UserID`),
  CONSTRAINT `FK_R_UserID` FOREIGN KEY (`UserID`) REFERENCES `User` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Rest Password Table for BaKaPlan';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `RollNoDetail`
--

DROP TABLE IF EXISTS `RollNoDetail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `RollNoDetail` (
  `RollNoID` int(50) NOT NULL AUTO_INCREMENT,
  `ClassID` int(50) NOT NULL,
  `Prefix` varchar(100) NOT NULL,
  `StartRollNo` int(70) NOT NULL,
  `EndRollNo` int(70) NOT NULL,
  `NotIncluded` varchar(200) NOT NULL DEFAULT '0',
  PRIMARY KEY (`RollNoID`),
  KEY `FK_ClassID` (`ClassID`),
  CONSTRAINT `FK_ClassID` FOREIGN KEY (`ClassID`) REFERENCES `ClassDetail` (`ClassID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COMMENT='Roll No details w.r.t class id';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `RoomDetail`
--

DROP TABLE IF EXISTS `RoomDetail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `RoomDetail` (
  `RoomID` int(50) NOT NULL AUTO_INCREMENT,
  `DateSheetID` int(50) NOT NULL,
  `CentreName` varchar(200) NOT NULL,
  `RoomNo` varchar(200) NOT NULL,
  `Rows` varchar(200) NOT NULL,
  `Columns` varchar(200) NOT NULL,
  `RoomInfo` varchar(200) NOT NULL,
  PRIMARY KEY (`RoomID`),
  KEY `FK_R_DateSheetID` (`DateSheetID`),
  CONSTRAINT `FK_R_DateSheetID` FOREIGN KEY (`DateSheetID`) REFERENCES `DateSheet` (`DateSheetID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `SessionDetail`
--

DROP TABLE IF EXISTS `SessionDetail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `SessionDetail` (
  `SessionID` int(50) NOT NULL AUTO_INCREMENT,
  `UserID` int(50) NOT NULL,
  `SessionKey` varchar(100) NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`SessionID`),
  KEY `UserID` (`UserID`),
  CONSTRAINT `SessionDetail_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `User` (`UserID`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=latin1 COMMENT='Session Detail for BaKaPlan';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `StrategyDetail`
--

DROP TABLE IF EXISTS `StrategyDetail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `StrategyDetail` (
  `StrategyID` int(50) NOT NULL AUTO_INCREMENT,
  `DateSheetID` int(50) NOT NULL,
  `StrategyNameID` int(50) NOT NULL,
  PRIMARY KEY (`StrategyID`),
  KEY `FK_S_DateSheetID` (`DateSheetID`),
  KEY `FK_StrategyNameID` (`StrategyNameID`),
  CONSTRAINT `FK_StrategyNameID` FOREIGN KEY (`StrategyNameID`) REFERENCES `StrategyName` (`StrategyNameID`),
  CONSTRAINT `FK_S_DateSheetID` FOREIGN KEY (`DateSheetID`) REFERENCES `DateSheet` (`DateSheetID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `StrategyName`
--

DROP TABLE IF EXISTS `StrategyName`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `StrategyName` (
  `StrategyNameID` int(50) NOT NULL AUTO_INCREMENT,
  `StrategyName` varchar(100) NOT NULL,
  PRIMARY KEY (`StrategyNameID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `User`
--

DROP TABLE IF EXISTS `User`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `User` (
  `UserID` int(50) NOT NULL AUTO_INCREMENT,
  `RegID` int(50) NOT NULL,
  `Password` varchar(50) NOT NULL,
  PRIMARY KEY (`UserID`),
  KEY `FK_RegID` (`RegID`),
  CONSTRAINT `FK_RegID` FOREIGN KEY (`RegID`) REFERENCES `Registration` (`RegID`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=latin1 COMMENT='User Table for BaKaPlan';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `ValidStrategy`
--

DROP TABLE IF EXISTS `ValidStrategy`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ValidStrategy` (
  `ValidID` int(50) NOT NULL AUTO_INCREMENT,
  `StrategyID` int(50) NOT NULL,
  `DateSheetID` int(50) NOT NULL,
  `TotalSeats` int(50) NOT NULL,
  `TotalStudents` int(50) NOT NULL,
  `TotalGroupSeats` int(50) NOT NULL,
  `TotalGroupStudents` int(50) NOT NULL,
  PRIMARY KEY (`ValidID`),
  KEY `FK_V_DateSheetID` (`DateSheetID`),
  KEY `FK_V_StrategyID` (`StrategyID`),
  CONSTRAINT `FK_V_DateSheetID` FOREIGN KEY (`DateSheetID`) REFERENCES `DateSheet` (`DateSheetID`),
  CONSTRAINT `FK_V_StrategyID` FOREIGN KEY (`StrategyID`) REFERENCES `StrategyDetail` (`StrategyID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2014-07-14 15:00:32
