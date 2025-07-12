-- AlterTable
ALTER TABLE "Task" ALTER COLUMN "createdAt" SET DEFAULT (now() AT TIME ZONE 'Asia/Kolkata');
